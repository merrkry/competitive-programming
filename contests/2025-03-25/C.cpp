#include <cstdio>
const int N = 2e5 + 5;
int ans[N];
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n;
    std::scanf("%d", &n);
    if (n % 2 == 1) {
      for (int i = n, pos = n; i >= 1; --i) {
        ans[pos] = i;
        pos -= 2;
        if (pos <= 0) {
          pos += n;
        }
      }
      for (int i = 1; i <= n; ++i) {
        std::printf("%d ", ans[i]);
      }
      std::printf("\n");
    } else {
      std::printf("-1\n");
    }
  }
  return 0;
}
