#include <cstdio>

const int N = 5e1 + 5;
int n, c[N];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int totA = 0, totB = 0;
    std::scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      char tmp;
      std::scanf(" %c", &tmp);
      c[i] = (tmp == 'A');
      if (c[i])
        ++totA;
      else
        ++totB;
    }
    bool res;
    if (c[1]) {
      if (c[n]) {
        res = 1;
      } else { // Alice has 1, Bob has n
        res = totB == 1;
      }
    } else {
      if (c[n]) { // Alice has n, Bob has 1
        if (totA == 1) {
          res = 0;
        } else {
          res = c[n - 1];
        }
      } else {
        res = 0;
      }
    }
    std::printf(res ? "Alice\n" : "Bob\n");
  }
}
