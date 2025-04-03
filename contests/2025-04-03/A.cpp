#include <cstdio>
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n;
    std::scanf("%d", &n);
    std::printf("%d\n", 2 * n);
  }
  return 0;
}
