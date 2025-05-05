#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>

typedef long long ll;
const int N = 4e5 + 5;

int n, m, k;
int tot_edges, nxt[N], head[N], cnt[N], to[N];
ll len[N], dist[2][N];
bool vis[N];

void add_edge(int u, int v, int w) {
  nxt[++tot_edges] = head[u];
  head[u] = tot_edges;
  to[tot_edges] = v;
  len[tot_edges] = w;
}

void dijkstra(ll *d, int st, int ed) {
  for (int i = 1; i <= n; ++i) {
    vis[i] = false;
    d[i] = 1LL << 62;
  }
  std::priority_queue<std::pair<ll, int>> q;
  q.push(std::make_pair(0, st));
  d[st] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    for (int i = head[u]; i != 0; i = nxt[i]) {
      int v = to[i];
      ll w = len[i];
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        q.push(std::make_pair(-d[v], v));
      }
    }
  }
}

struct store {
  double p;
  ll sum;
} stores[N];

// void print_arr(ll *d) {
//   for (int i = 1; i <= n; ++i) {
//     std::printf("%lld ", d[i]);
//   }
//   std::printf("\n");
// }

int main() {
  std::scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    int x, y, l;
    std::scanf("%d%d%d", &x, &y, &l);
    add_edge(x, y, l);
    add_edge(y, x, l);
  }
  dijkstra(dist[0], 1, n);
  dijkstra(dist[1], n, 1);
  double max_p = 0.0;
  for (int i = 1; i <= k; ++i) {
    int x;
    double p;
    std::scanf("%d%lf", &x, &p);
    stores[i].p = p;
    stores[i].sum = dist[0][x] + dist[1][x];
    max_p = std::max(max_p, p);
  }
  if (max_p < 1.0) {
    std::printf("impossible\n");
    return 0;
  }
  // print_arr(dist[0]);
  // print_arr(dist[1]);
  std::sort(stores + 1, stores + k + 1,
            [](store s1, store s2) -> bool { return s1.sum < s2.sum; });
  double sum_p = 0, mul_p = 1, ans = 0;
  for (int i = 1; i <= k; ++i) {
    if (stores[i].p == 1.0) {
      ans += (1 - sum_p) * stores[i].sum;
      break;
    } else {
      ans += mul_p * stores[i].p * stores[i].sum;
      sum_p += mul_p * stores[i].p;
      mul_p *= (1 - stores[i].p);
    }
  }
  std::printf("%lf", ans);
  return 0;
}
