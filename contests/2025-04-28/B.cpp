#include <algorithm>
#include <cstdio>

typedef long long ll;
const int N = 2e5 + 5;
int n, a[N];
ll pre_sum[N], pre_max[N];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", a + i);
    }

    for (int i = 1; i <= n; ++i) {
      pre_sum[i] = pre_sum[i - 1] + a[i];
      pre_max[i] = std::max(pre_max[i - 1], (ll)a[i]);
    }

    for (int i = 1; i <= n; ++i) {
      ll val = pre_sum[n] - pre_sum[n - i + 1] + pre_max[n - i + 1];
      std::printf("%lld ", val);
    }
    std::printf("\n");
  }
  return 0;
}
