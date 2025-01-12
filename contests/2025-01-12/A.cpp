#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if ((a - b) % 2) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
