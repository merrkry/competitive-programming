#include <cstdio>
const int N = 1e5 + 5;

int n, p[N];
bool b[N];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", &p[i]);
      b[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      int d;
      std::scanf("%d", &d);
      for (int j = d; b[j]; j = p[j]) {
        ++cnt;
        b[j] = 0;
      }
      std::printf("%d ", cnt);
    }
    std::printf("\n");
  }
  return 0;
}
