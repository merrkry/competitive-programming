#include <algorithm>
#include <cstdio>
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n, m, k;
    std::scanf("%d%d%d", &n, &m, &k);
    int L = 1, R = m, mid, ans = m;
    while (L <= R) {
      mid = (L + R) / 2;
      int num1 = k % n == 0 ? k / n : k / n + 1,
          num2 = m / (mid + 1) * mid + m % (mid + 1);
      if (num1 <= mid || num1 <= num2) {
        R = mid - 1;
        ans = std::min(ans, mid);
      } else {
        L = mid + 1;
      }
    }
    std::printf("%d\n", ans);
  }
  return 0;
}
