#include <bits/stdc++.h>
using namespace std;

int get_len(int x) {
  int ans = 0;
  while (x > 1) {
    x >>= 1;
    ++ans;
  }
  return ans;
}

int get(int x, int h) { return h >= 0 ? (x >> h) & 1 : 0; }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int l, r;
    scanf("%d%d", &l, &r);

    int h1 = get_len(l ^ r), h2 = -1;
    for (int i = h1 - 1; i >= 0; --i) {
      if (get(l, i) == get(r, i)) {
        h2 = i;
        break;
      }
    }
    // printf("h1 = %d, h2 = %d\n", h1, h2);
    int ans = (l >> (h1 + 1)) << (h1 + 1);
    bool sign;
    if (h2 >= 0) {
      sign = get(l, h2) ^ 1;
      ans += (sign << h2);
    } else {
      sign = (l + 1) & 1 ^ 1;
    }
    for (int i = h2 + 1, s = sign ^ 1; i <= h1; ++i, s ^= 1) {
      ans += ((s) << i);
    }
    for (int i = h2 - 1; i >= 0; --i) {
      if (!(get(l, i) == 1 && get(r, i) == 1)) {
        ans += (1 << i);
      }
    }
    printf("%d %d %d\n", l, ans, r);
    // printf("ANS = %lld\n", (long long)(l ^ ans) + (ans ^ r) + (l ^ r));
  }
}
