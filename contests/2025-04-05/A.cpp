#include <cstdio>
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n;
    std::scanf("%d", &n);

    if (n % 2 == 1) {
      for (int i = 1; i <= n; ++i) {
        std::printf("%d ", i == 1 ? n : i - 1);
      }
      std::printf("\n");
    } else {
      std::printf("-1\n");
    }
  }
  return 0;
}
