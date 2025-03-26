#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);

    int p1 = 1, p2 = 2, p3 = 3;
    int e1 = 0, e2 = 0, e3 = 0; // (p1, p2), (p1, p3), (p2, p3)
    for (int i = 1; i <= 75; ++i) {
      printf("? %d %d %d\n", p1, p2, p3);
      fflush(stdout);

      int ans;
      scanf("%d", &ans);
      if (ans == 0 || i == 75) {
        printf("! %d %d %d\n", p1, p2, p3);
        fflush(stdout);
        break;
      } else {
        // find the oldest edge, select the point on the opposite, one of its
        // endpoint, as well as the query answer to dive in.
        if (e1 <= e2 && e1 <= e3) { // e1(p1, p2)
          p2 = ans;
          e1 = e3 = i;
        } else if (e2 <= e1 || e2 <= e3) { // e2(p1, p3)
          p3 = ans;
          e2 = e3 = i;
        } else { // e3(p2, p3)
          p3 = ans;
          e2 = e3 = i;
        }
      }
    }
  }
}
