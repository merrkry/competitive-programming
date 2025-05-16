#include <algorithm>
#include <cstdio>
#include <set>

typedef long long ll;

const int N = 5e3 + 5;
const int M = 2e1 + 5;
const ll MAX = 1LL << 62;

int n, k, n_val;
ll a[N], b[N], c[N], dp[N][M], prev[N][N];

ll square(ll x) { return x * x; }

int main() {
  std::scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    std::scanf("%lld", a + i);
    b[i] = a[i];
  }

  std::sort(b + 1, b + n + 1);
  n_val = std::unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; ++i) {
    c[i] = std::lower_bound(b + 1, b + n_val + 1, a[i]) - b;
  }
  std::sort(c + 1, c + n + 1);

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      dp[i][j] = MAX;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      ll sum = 0;
      for (int k = i - 1; k >= 0; --k) {
        if (sum + dp[k][j - 1] < dp[i][j]) {
          dp[i][j] = sum + dp[k][j - 1];
          prev[i][j] = k;
        }
        sum += square(b[c[i]] - b[c[k]]);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= std::min(n, k); ++i) {
    if (!ans || dp[n][i] < dp[n][ans]) {
      ans = i;
    }
  }

  std::set<ll> sch;
  int pos = n;
  while (prev[pos][ans]) {
    sch.insert(b[prev[pos][ans]]);
    pos = prev[pos][ans];
    --ans;
  }

  return 0;
}
