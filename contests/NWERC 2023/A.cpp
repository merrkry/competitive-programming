#include <algorithm>
#include <cstdio>

const int N = 2e5 + 5;

int n, s, w[N];

int main() {
  std::scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; ++i) {
    std::scanf("%d", w + i);
  }

  if (n <= 2 || s <= 2) {
    std::printf("%d\n", std::min(n, s));
    return 0;
  }

  std::sort(w + 1, w + n + 1);

  int cnt = 2, res = 0, ans = 2;
  for (int i = 1; i <= n - 2; ++i) {
    // w[i] = 3k + t
    int k = w[i] / 3, t = w[i] % 3;
    if (res >= t && k <= s - cnt) {
      cnt += k;
      res = 0;
      ++ans;
    } else if (k + (t > 0 ? 1 : 0) <= s - cnt) {
      cnt += k + (t > 0 ? 1 : 0);
      res = t > 0 ? 3 - t : 0;
      ++ans;
    } else {
      break;
    }
  }

  std::printf("%d\n", ans);

  return 0;
}
