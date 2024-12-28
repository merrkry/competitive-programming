#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int n, a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ans = false;
    for (int i = 1; i <= n - 1 && !ans; ++i) {
      int x = min(a[i], a[i + 1]), y = max(a[i], a[i + 1]);
      if (x * 2 > y) {
        ans = true;
        break;
      }
    }
    printf(ans ? "YES\n" : "NO\n");
  }
  return 0;
}
