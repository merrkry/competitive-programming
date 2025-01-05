#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", (a ^ b) + (b ^ c) + (a ^ c));
  }
  return 0;
}
