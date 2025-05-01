#include <algorithm>
#include <csignal>
#include <cstdio>

typedef long long ull;

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n, x;
    std::scanf("%d%d", &n, &x);

    if (n == 1) {
      if (x != 0) {
        std::printf("%d\n", x);
      } else {
        std::printf("-1\n");
      }
      continue;
    }

    ull ans = 0;
    bool is_odd[32];
    int cnt = 0;
    for (int i = 0; i < 32; ++i) {
      is_odd[i] = x & (1 << i);
      if (is_odd[i]) {
        ++cnt;
        ans += (1 << i);
      }
    }

    int res = n - cnt;
    for (int i = 0; i < 32 && res > 0; ++i) {
      int avail = (n - is_odd[i]) / 2 * 2;
      // std::printf("DEBUG: %d %d %d\n", i, avail, res);
      if (avail <= 0)
        continue;
      if (res > 1) {
        int deducted = std::min(res / 2 * 2, avail);
        ans += (ull)deducted * (1 << i);
        res -= deducted;
        avail -= deducted;
        // std::printf("DEBUG: %d %d\n", deducted, res);
      }
      if (res == 1 && avail >= 2) {
        res -= 1;
        ans += 2LL * (1 << i);
      }
    }
    std::printf("%lld\n", res <= 0 ? ans : -1ULL);
  }
  return 0;
}
