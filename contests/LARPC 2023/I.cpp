#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 1e5 + 5;
const ll M = 1e9 + 7;

ll n, r, len, tot, cnt[26];
char str[N];

ll qpow(ll x, ll p) {
  ll res = 1;
  for (; p > 0; p /= 2) {
    if (p & 1)
      res = (res * x) % M;
    x = (x * x) % M;
  }
  return res;
}

ll mul(ll x, ll y) {
  x %= M;
  y %= M;
  return x * y % M;
}

int main() {
  std::scanf("%s", str);
  len = strlen(str);
  std::scanf("%lld", &n);
  for (int i = len - 1; i >= 0; --i) {
    int a = str[i] - 'a';
    ll sum = 0;
    for (int j = 0; j < a; ++j) {
      sum += cnt[j];
    }
    r = (r + sum) % M;
    ++cnt[a];
    cnt[a] %= M;
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = i + 1; j < 26; ++j) {
      tot = (tot + cnt[i] * cnt[j] % M) % M;
    }
  }
  std::printf("%lld\n",
              ((n % M) * r % M + mul(mul(n, n - 1), qpow(2, M - 2)) * tot % M) %
                  M);
  return 0;
}
