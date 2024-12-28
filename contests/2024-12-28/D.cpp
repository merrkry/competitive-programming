#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
const int M = 998244353;

int n, q, a[N], b[N], val[2 * N], c[N], d[N], m[2][N], aa[N], bb[N];
multimap<int, int> da, db; // origin -> disc

int mod(int ans, int x, int y, int factor) {
  return factor == 1 ? (long long)ans * x * y : (long long)ans - x - y;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &q);
    val[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      val[++val[0]] = a[i];
      aa[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      val[++val[0]] = b[i];
      bb[i] = b[i];
    }

    for (int i = 1; i <= q; ++i) {
      scanf("%d%d", &m[0][i], &m[1][i]);
      if (m[0][i] == 1) {
        val[++val[0]] = ++aa[m[1][i]];
      } else {
        val[++val[0]] = ++bb[m[1][i]];
      }
    }

    sort(val + 1, val + val[0] + 1);
    val[0] = unique(val + 1, val + val[0] + 1) - (val + 1);
    for (int i = 1; i <= n; ++i) {
      c[i] = lower_bound(val + 1, val + val[0] + 1, a[i]) - val;
      da.insert(val[c[i]], c[i]);
      d[i] = lower_bound(val + 1, val + val[0] + 1, b[i]) - val;
      db.insert(val[d[i]], d[i]);
    }

    sort(c + 1, c + n + 1);
    sort(d + 1, d + n + 1);
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
      // printf("a' = %d b' = %d\n", c[i], d[i]);
      ans = (long long)ans * min(val[c[i]], val[d[i]]) % M;
    }
    printf("%d\n", ans);

    for (int i = 1; i <= q; ++i) {
      int pos = m[1][i];
      if (m[0][i] == 1) { // a
        int x = lower_bound(val + 1, val + val[0] + 1, a[pos]) -
                (val + 1);                                  // value in c[]
        int y = lower_bound(c + 1, c + n + 1, x) - (c + 1); // index in c[]
        if (y == n || val[x] + 1 <= val[c[y + 1]])
          continue;

      } else { // b
      }
    }

    da.clear();
    db.clear();
  }
  return 0;
}
