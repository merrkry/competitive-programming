#include <algorithm>
#include <cstdio>

typedef long long ll;
const int N = 1e5 + 5;

int n, k, a[N];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d%d", &n, &k);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", a + i);
      sum += a[i];
    }
    std::sort(a + 1, a + n + 1);
    if (a[n] - (a[1] - 1) > k && std::max(a[n] - 1, a[n - 1]) - a[1] >
                                     k) { // Toms loses after first move
      std::printf("Jerry\n");
      continue;
    }
    std::printf(sum % 2 ? "Tom\n" : "Jerry\n");
  }
  return 0;
}
