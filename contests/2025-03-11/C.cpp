#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x;
    scanf("%d", &x);
    int p1, p2;
    p1 = p2 = -1;
    for (int i = 30; i >= 0; --i) {
      if (p1 == -1 && (x & (1 << i)) > 0) {
        p1 = i;
        continue;
      }
      if (p1 != -1 && p2 == -1 && (x & (1 << i)) == 0) {
        p2 = i;
        break;
      }
    }
    // printf("p1 = %d, p2 = %d\n", p1, p2);
    if (p1 == -1 || p2 == -1) {
      printf("-1\n");
    } else {
      int y = x ^ (1 << p1) | (1 << p2);
      if (x + y == (x ^ y)) {
        printf("-1\n");
      } else {
        printf("%d\n", y);
        // printf("ANS: %d %d %d\n", x, y, x ^ y);
      }
    }
  }
  return 0;
}
