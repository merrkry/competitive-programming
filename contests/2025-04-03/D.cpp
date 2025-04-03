#include <algorithm>
#include <cstdio>

typedef long long ll;

const int N = 1e2 + 5;
const int M = 998244353;

int cnt, tot, c[N], sum[N];

int qpower(int x, int y) {
  ll ans = 1;
  x %= M;
  while (y) {
    if (y & 1) {
      ans = (ans * x) % M;
    }
    x = ((ll)x * x) % M;
    y /= 2;
  }
  return ans;
}

int rev(int x) { return qpower(x, M - 2); }

int fac(int x) {
  ll mul = x;
  while (--x) {
    mul = (mul * x) % M;
  }
  return mul;
}

int revFac(int x) { return rev(fac(x)); }

void search(int pos, int cnt1, int ans1, int cnt2, int ans2) {
  printf("DEBUG: %d %d %d %d %d\n", pos, cnt1, ans1, cnt2, ans2);
  if (c[pos] == 0) {
    if (cnt1 != 0 || cnt2 != 0) {
      std::printf("ERROR!\n");
    }
    cnt += ((ll)ans1 * ans2 % M);
    return;
  }
  if (cnt1 >= c[pos])
    search(pos + 1, cnt1 - c[pos], (ll)ans1 * revFac(c[pos]) % M, cnt2, ans2);
  if (cnt2 >= c[pos])
    search(pos + 1, cnt1, ans1, cnt2 - c[pos], (ll)ans2 * revFac(c[pos]) % M);
}

int main() {
  // std::printf("%d\n", qpower(3, 4));
  // std::printf("%d\n", rev(2));
  // std::printf("%d\n", revFac(2));
  int T;
  std::scanf("%d", &T);
  while (T--) {
    cnt = 0;
    for (int i = 1; i <= 26; ++i) {
      std::scanf("%d", &c[i]);
    }
    std::sort(c + 1, c + 26 + 1, [](int x, int y) { return x > y; });
    for (int i = 1; i <= 26; ++i) {
      sum[i] = sum[i - 1] + c[i];
    }
    tot = sum[26];
    search(1, tot / 2, fac(tot / 2), tot - tot / 2, fac(tot - tot / 2));
    std::printf("%d\n", cnt);
  }
  return 0;
}
