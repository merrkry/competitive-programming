#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      int tmp;
      scanf("%d", &tmp);
      ans += tmp;
    }
    ans -= (n - 1);
    printf("%lld\n", ans);
  }
  return 0;
}
