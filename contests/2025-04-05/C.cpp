#include <cstdio>
const int N = 2e5 + 5;

int n, a[N], b[N], c[N], d[N];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      c[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      d[i] = c[b[i]];
      std::printf("%d ", d[i]);
    }
    std::printf("\n");
  }
  return 0;
}
