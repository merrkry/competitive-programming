#include <algorithm>
#include <cstdio>
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n;
    std::scanf("%d", &n);
    bool las = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
      char c;
      std::scanf(" %c", &c);
      if ((c - '0') != las) {
        if (c - '0')
          ++cnt1;
        else
          ++cnt2;
        las = c - '0';
      }
    }
    // std::printf("DEBUG: %d %d\n", cnt1, cnt2);
    int ans = n + cnt1 + cnt2;
    if (std::max(cnt1, cnt2) >= 2) {
      ans -= 2;
    } else if ((cnt1 >= 1 && las == 0) || (cnt2 >= 1 && las == 1)) {
      ans -= 1;
    }
    std::printf("%d\n", ans);
  }
}
