#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 4e5 + 5;

int n;
int l[N], r[N], val[N], cnt[N], sum[N];

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    val[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &l[i], &r[i]);
      val[++val[0]] = l[i];
      val[++val[0]] = r[i];
    }
    sort(val + 1, val + val[0] + 1);
    val[0] = unique(val + 1, val + val[0] + 1) - val - 1;
    for (int i = 1; i <= n; ++i) {
      l[i] = lower_bound(val + 1, val + val[0] + 1, l[i]) - val;
      r[i] = lower_bound(val + 1, val + val[0] + 1, r[i]) - val;
      if (l[i] == r[i]) {
        ++cnt[l[i]];
      }
    }
    for (int i = 1; i <= val[0]; ++i) {
      sum[i] = sum[i - 1] + (cnt[i] >= 1 ? 1 : 0);
    }

    // printf("SUM: ");
    // for (int i = 1; i <= val[0]; ++i) {
    //   printf("%d", sum[i]);
    // }
    // printf("\n");

    for (int i = 1; i <= n; ++i) {
      if (l[i] == r[i] && cnt[l[i]] == 1)
        printf("1");
      else if (l[i] < r[i] &&
               sum[r[i]] - sum[l[i] - 1] < val[r[i]] - val[l[i]] + 1)
        printf("1");
      else
        printf("0");
    }
    printf("\n");

    for (int i = 1; i <= val[0]; ++i) {
      sum[i] = 0;
      cnt[i] = 0;
    }
  }

  return 0;
}
