#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", max(n, m) + 1);
  }
  return 0;
}
