#include <bits/stdc++.h>

const int N = 2e5 + 5;

int n;
int a[N], b[N];
long long d[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    long long minA = 1 << 30;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      minA = std::min((long long)a[i], minA);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      d[i] = a[i] - b[i];
    }
    std::sort(d + 1, d + n + 1);

    bool ans;
    if (d[2] < 0) {
      ans = false;
    } else if (d[1] >= 0) {
      ans = true;
    } else {
      ans = -d[1] <= d[2];
    }

    printf(ans ? "YES\n" : "NO\n");
  }
  return 0;
}
