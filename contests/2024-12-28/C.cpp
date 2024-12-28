#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, k, ans = 0;
    scanf("%lld%lld", &n, &k);
    long long len = n, cnt = 1;
    while (len >= k) {
      if (len % 2 == 1) {
        ans += ((1 + len) / 2 + (2 * n - len + 1) / 2) * cnt / 2;
      }
      len /= 2;
      cnt *= 2;
    }
    printf("%lld\n", ans);
  };
  return 0;
}
