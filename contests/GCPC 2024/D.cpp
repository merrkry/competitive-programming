#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;

int n, q;
ll p, rp, pre_ft[N], suf_ft[N];
char input_buffer[10];

ll qpow(ll x, ll k) {
  ll res = 1;
  for (; k > 0; k /= 2) {
    if (k & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
  }
  return res;
}

ll rev(ll x) { return qpow(x, mod - 2); }

void parse_decimal() {
  ll num = 0, den = 1;
  for (int i = 2; i < strlen(input_buffer); ++i) {
    num *= 10;
    num += input_buffer[i] - '0';
    den *= 10;
  }
  // std::printf("%d %d", num, den);
  p = (num * rev(den)) % mod;
  p = (1 - p + mod) % mod;
  rp = rev(p);
}

int lsb(int x) { return x & -x; }

void ft_modify(ll *ft, int pos, ll val) {
  for (; pos <= n; pos += lsb(pos)) {
    ft[pos] = (ft[pos] + val) % mod;
  }
}

ll ft_query(ll *ft, int pos) {
  ll res = 0;
  for (; pos > 0; pos -= lsb(pos)) {
    res = (res + ft[pos]) % mod;
  }
  return res;
}

void modify(int pos, ll val) {
  ft_modify(pre_ft, pos, val * qpow(p, n - pos) % mod);
  ft_modify(suf_ft, n - pos + 1, val * qpow(p, pos - 1) % mod);
}

ll query(int pos) {
  ll res = 0;
  res += ft_query(pre_ft, pos) * qpow(rp, n - pos) % mod;
  res %= mod;
  res += ft_query(suf_ft, n - (pos + 1) + 1) * qpow(rp, pos - 1) % mod;
  res %= mod;
  return res;
}

int main() {
  std::scanf("%d %d %s", &n, &q, input_buffer);
  parse_decimal();
  for (int i = 1; i <= q; ++i) {
    char opt;
    int b, x;
    std::scanf(" %c", &opt);
    switch (opt) {
    case '+':
      std::scanf("%d %d", &b, &x);
      modify(x, b);
      break;
    case '-':
      std::scanf("%d %d", &b, &x);
      modify(x, mod - b);
      break;
    case '?':
      std::scanf("%d", &x);
      std::printf("%lld\n", query(x));
      break;
    }
  }
  return 0;
}
