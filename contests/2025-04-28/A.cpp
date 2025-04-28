#include <cstdio>

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int a, b, c;
    std::scanf("%d%d%d", &a, &b, &c);
    int tot = a + b + c;
    if (tot % 3 == 0 && b <= tot / 3) {
      std::printf("YES\n");
    } else {
      std::printf("NO\n");
    }
  }
  return 0;
}
