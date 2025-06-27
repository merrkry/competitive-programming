#include <algorithm>
#include <cstdio>
#include <functional>

bool DEBUG = false;

typedef long long ll;

const ll INF = 1LL << 62;
const int N = 2e5 + 5;

struct SegmentTree {
  ll inf;
  ll nodes[N << 2];
  std::function<ll(ll, ll)> merge;

  void init(int id, int L, int R) {
    if (L == R) {
      nodes[id] = inf;
      return;
    }
    int Mid = (L + R) / 2;
    init(id * 2, L, Mid);
    init(id * 2 + 1, Mid + 1, R);
  }

  void modify(int id, int L, int R, int pos, ll val) {
    if (L == R) {
      nodes[id] = merge(nodes[id], val);
      return;
    }
    int Mid = (L + R) / 2;
    if (pos <= Mid)
      modify(id * 2, L, Mid, pos, val);
    else
      modify(id * 2 + 1, Mid + 1, R, pos, val);
    nodes[id] = merge(nodes[id * 2], nodes[id * 2 + 1]);
  }

  ll query(int id, int L, int R, int l, int r) {
    if (L > R) {
      return inf;
    }
    if (l <= L && R <= r) {
      return nodes[id];
    }
    int Mid = (L + R) / 2;
    ll ans = inf;
    if (l <= Mid) {
      ans = merge(ans, query(id * 2, L, Mid, l, r));
    }
    if (r > Mid) {
      ans = merge(ans, query(id * 2 + 1, Mid + 1, R, l, r));
    }
    return ans;
  }
};

struct Range {
  int L, R;

  friend bool operator<(Range x, Range y) { return x.R < y.R; }
};

int n, m, exh_cnt, lg2[N];
ll min_end = INF, max_start = -INF;
ll discomfort[N], exh[N][20];
SegmentTree F{.inf = INF, .nodes = {}, .merge = [](ll a, ll b) -> ll {
                return std::min(a, b);
              }};

int query_exh(int L, int R) {
  int s = lg2[R - L + 1];
  return std::max(exh[L][s], exh[R - (1 << s) + 1][s]);
}

int main() {
  std::scanf("%d%d", &n, &m);

  lg2[1] = 0;
  for (int i = 2; i <= n; ++i) {
    lg2[i] = lg2[i / 2] + 1;
  }

  for (int i = 1; i <= n; ++i) {
    std::scanf("%lld", &discomfort[i]);

    exh[i][0] = -INF;
  }
  for (int i = 1; i <= m; ++i) {
    int st, ed;
    std::scanf("%d%d", &st, &ed);

    min_end = std::min(min_end, (ll)ed);
    max_start = std::max(max_start, (ll)st);

    exh[ed][0] = std::max(exh[ed][0], (ll)st);
  }

  for (int j = 1; j < 20; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      exh[i][j] = std::max(exh[i][j - 1], exh[i + (1 << (j - 1))][j - 1]);
    }
  }

  F.init(1, 1, n);

  for (int i = 1; i <= n; ++i) {
    if (min_end >= i) {
      F.modify(1, 1, n, i, discomfort[i]);
    }

    int L = 1, R = i - 1, Mid, target = 0;
    while (L <= R) {
      Mid = (L + R) / 2;
      if (Mid + 1 <= i - 1 &&
          query_exh(Mid + 1, i - 1) > Mid) { // uncovered range exits, not valid
        L = Mid + 1;
      } else {
        R = Mid - 1;
        target = Mid;
      }
    }

    if (target == 0) {
      continue;
    }

    ll res = F.query(1, 1, n, target, i - 1) + discomfort[i];
    F.modify(1, 1, n, i, res);

    if (DEBUG)
      std::printf("i = %d, target = %d, F_i = %lld\n", i, target,
                  F.query(1, 1, n, i, i));
  }

  ll answer = F.query(1, 1, n, max_start, n);
  std::printf("%lld\n", answer);

  return 0;
}
