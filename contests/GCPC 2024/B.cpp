#include <algorithm>
#include <cstdio>

typedef long long ll;

int n, H, l[3];
ll ans;

int main() {
  std::scanf("%d%d", &n, &H);
  for (int i = 1; i <= n; ++i) {
    std::scanf("%d%d%d", l + 0, l + 1, l + 2);
    std::sort(l, l + 3);
    if (l[1] > H) {
      if (l[0] > H) {
        std::printf("impossible\n");
        return 0;
      } else {
        ans += l[1];
      }
    } else {
      ans += l[0];
    }
  }
  std::printf("%lld\n", ans);
  return 0;
}
