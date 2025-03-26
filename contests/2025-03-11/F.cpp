#include <bits/stdc++.h>
#include <utility>
using namespace std;

struct reg {
  int l1, r1, l2, r2;
};

stack<reg> st;

// a * 2**k, (a + 1) * 2**
pair<int, int> solve(int l, int r) {
  for (int i = 30; i >= 0; --i) {
    int p = 1 << i, a = l % p == 0 ? l / p : l / p + 1;
    if (r - l < p || (a + 1) * p > r) // FIXME
      continue;
    printf("solved: %d %d %d %d\n", l, r, a * p, (a + 1) * p);
    return make_pair(a * p, (a + 1) * p);
  }
  return make_pair(0, 0); // shall not be triggered.
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int _l1, _r1, _l2, _r2;
    scanf("%d%d%d%d", &_l1, &_r1, &_l2, &_r2);

    st.push(reg{_l1, _r1, _l2, _r2});
    long long ans = 0;
    while (!st.empty()) {
      reg now = st.top();
      st.pop();
      int l1 = now.l1, l2 = now.l2, r1 = now.r1, r2 = now.r2;
      printf("found: %d %d %d %d\n", l1, r1, l2, r2);

      auto pair = solve(l1, r1);
      int l3 = pair.first, r3 = pair.second;
      pair = solve(l2, r2);
      int l4 = pair.first, r4 = pair.second;

      ans += max((r3 - l3) / (r4 - l4), (r4 - l4) / (r3 - l3));

      if (l2 < l4 - 1) {
        st.push(reg{l1, r1, l2, l4 - 1});
      }
      if (r4 < r2 - 1) {
        st.push(reg{l1, r1, r4 + 1, r2});
      }
      if (l1 < l3 - 1) {
        st.push(reg{l1, r3 - 1, l4, r4});
      }
      if (r3 < r1 - 1) {
        st.push(reg{r3 + 1, r1, l4, r4});
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
