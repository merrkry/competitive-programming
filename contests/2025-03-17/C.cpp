#include <algorithm>
#include <cstdio>
typedef long long ll;
const int N = 2e5 + 5;
int n, m, a[N];
ll pre[N];
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
      a[i] = std::min(a[i], n - 1);
    }

    std::sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; ++i) {
      pre[i] = pre[i - 1] + a[i];
    }

    long long ans = 0;
    for (int i = 1, j = m; i < m; ++i) {
      while (a[i] + a[j] >= n && j > 0)
        --j;
      if (j != m) {
        int k = std::max(i, j);
        ll num = m - k;
        ans += (num * a[i] + pre[m] - pre[k] - num * n + num) * 2;
      }
    }

    std::printf("%lld\n", ans);
  }
}
