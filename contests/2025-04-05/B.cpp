#include <algorithm>
#include <cstdio>
typedef long long ll;

const int N = 2e5 + 5;

int n;
ll a[N], b[N];

ll gcd(ll x, ll y) { return x ? gcd(y % x, x) : y; }

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%lld", &a[i]);
    }
    std::sort(a + 1, a + n + 1);
    b[0] = 0;
    for (int i = 2; i <= n; ++i) {
      if (a[i] % a[1] == 0) {
        b[++b[0]] = a[i];
      }
    }
    if (b[0] == 0) {
      std::printf("No\n");
      continue;
    }
    ll res = b[1];
    for (int i = 2; i <= b[0]; ++i) {
      res = gcd(res, b[i]);
    }
    if (res == a[1]) {
      std::printf("Yes\n");
    } else {
      std::printf("No\n");
    }
  }
  return 0;
}
