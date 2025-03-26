#include <cstdio>
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    // std::printf("T: %d!", T);
    int n, k, ans = 0;
    std::scanf("%d%d", &n, &k);

    if (n % 2 == 1) {
      n -= k;
      ++ans;
    }

    if (n <= 0) {
      goto output;
    }

    ans += n / (k - 1);
    n %= (k - 1);
    // printf("n = %d, k = %d\n", n, k);

    if (n <= 0) {
      goto output;
    }

    ++ans;
    // printf("!\n");

  output:
    std::printf("%d\n", ans);
  }
  return 0;
}
