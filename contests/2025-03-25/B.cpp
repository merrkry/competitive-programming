#include <algorithm>
#include <cstdio>
const int N = 2e5 + 5;
int n, x, a[N];
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", &a[i]);
    }
    std::sort(a + 1, a + n + 1, [](int num1, int num2) { return num1 > num2; });
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
      ++cnt;
      if ((long long)a[i] * cnt >= x) {
        cnt = 0;
        ++ans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
