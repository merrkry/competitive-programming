#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int N = 1e6 + 5;
int n, m, x[N], r[N];
map<int, int> mp;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    mp.clear();

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &r[i]);
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = x[i] - r[i]; j <= x[i] + r[i]; ++j) {
        int y = floor(sqrt(r[i] * r[i] - (j - x[i]) * (j - x[i])));
        if (mp.find(j) != mp.end()) {
          mp[j] = max(mp[j], y);
        } else {
          mp[j] = y;
        }
      }
    }

    long long ans = 0;
    for (const auto &pair : mp) {
      ans += (pair.second == 0 ? 1 : 2 * pair.second + 1);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
