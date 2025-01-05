#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
int cnt[N];
map<int, int> mp;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      int a;
      scanf("%d", &a);
      if (mp.find(a) == mp.end()) {
        mp[a] = 1;
      } else {
        ++mp[a];
      }
    }
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
      ++cnt[it->second];
    }

    int L = 1;
    while (k > 0) {
      while (cnt[L] == 0 && L <= n)
        ++L;
      if (L > n || L > k)
        break;
      cnt[L] -= 1;
      k -= L;
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += cnt[i];
      cnt[i] = 0;
    }
    printf("%d\n", max(sum, 1));
    mp.clear();
  }
  return 0;
}
