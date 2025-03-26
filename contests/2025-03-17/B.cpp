#include <algorithm>
#include <cstdio>
const int N = 5e3 + 5;
int n, k, a[N];
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", &a[i]);
    }
    if (k == 1) {
      long long ans = a[1] + a[n];
      for (int i = 2; i <= n - 1; ++i) {
        ans = std::max((long long)a[1] + a[i], ans);
        ans = std::max((long long)a[n] + a[i], ans);
      }
      printf("%lld\n", ans);
    } else {
      std::sort(a + 1, a + n + 1, [](int x, int y) { return x > y; });
      long long ans = 0;
      // std::printf("DEBUG: ");
      for (int i = 1; i <= k + 1; ++i) {
        ans += a[i];
        // std::printf("%d ", a[i]);
      }
      std::printf("%lld\n", ans);
    }
  }
  return 0;
}
