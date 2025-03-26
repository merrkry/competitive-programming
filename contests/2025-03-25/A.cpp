#include <array>
#include <cstdio>
int main() {
  int T;
  std::scanf("%d", &T);
  std::array<int, 5> req = {3, 1, 2, 1, 1};
  while (T--) {
    int n;
    scanf("%d", &n);
    auto cnt = req;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp == 0 || tmp == 1 || tmp == 2 || tmp == 3 || tmp == 5) {
        cnt[tmp == 5 ? tmp - 1 : tmp] -= 1;
      }
      if (ans == 0) {
        bool done = true;
        for (auto elem : cnt) {
          if (elem > 0) {
            done = false;
            break;
          }
        }
        if (done) {
          ans = i;
        }
      }
    }
    std::printf("%d\n", ans);
  }
}
