#include <algorithm>
#include <cstdio>
typedef long long ll;

const int N = 1e5 + 5;

ll n, k, x, a[N], sum[N];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%lld%lld%lld", &n, &k, &x);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%lld", &a[i]);
      sum[i] = sum[i - 1] + a[i];
    }

    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
      ll l1 = 0, l2 = 0, l3 = 0;

      if (sum[n] - sum[i - 1] >= x) {
        l1 = std::lower_bound(sum + 1, sum + n + 1, x + sum[i - 1]) - (sum + 1);
        ans += ((ll)(k + 1) * n * k / 2 - (ll)k * (i + l1 - 1));
      } else {
        l1 = n - i;
        ll y = x - (sum[n] - sum[i - 1]);
        l2 = y / sum[n] * n;
        ll z = y % sum[n];
        if (z > 0) {
          l3 = std::lower_bound(sum + 1, sum + n + 1, z) - (sum + 1);
        }
        ll l = l1 + l2 + l3;

        ll left = 1, right = k, mid, p;
        while (left < right) {
          mid = (left + right) / 2;
          ll res = (ll)(k - mid + 1) * n - i;
          if (res >= l) {
            left = mid + 1;
            p = mid;
          } else {
            right = mid - 1;
          }
        }

        ans += (p * ((ll)k * n - i - l + 1) - (ll)p * (p - 1) * n / 2);
      }
    }

    std::printf("%lld\n", ans);
  }
  return 0;
}
