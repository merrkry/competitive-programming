#include <cmath>
#include <cstdio>
#include <numeric>
#include <set>
#include <utility>

typedef long long ll;

ll a, b, c, d;

std::set<std::pair<ll, ll>> cache;

void simplify(ll &x, ll &y) {
  ll z = std::gcd(x, y);
  x /= z;
  y /= z;
}

bool solve(ll _a, ll _b) {
  ll z = std::gcd(_a, _b);
  if (_a / z == c && _b / z == d) {
    std::printf("possible\n%lld %lld\n", _a, _b);
    return true;
  }
  return false;
}

int get_num(ll val, int pos) {
  for (int i = 1; i < pos; ++i) {
    val /= 10;
  }
  return val % 10;
}

ll del_num(ll val, ll pos) {
  ll mul = std::pow(10, pos - 1);
  return val / mul / 10 * mul + val % mul;
}

ll get_len(ll val) {
  int cnt = 0;
  while(val > 0) {
    ++cnt;
    val /= 10;
  }
  return cnt;
}

bool search(ll x, ll y) {
  if(solve(x, y)) {
    return true;
  }
  
  if (cache.find(std::make_pair(x, y)) != cache.end()) {
    return false;
  }

  if(x >= 10 && y >= 10) {
    int len_x = get_len(x);
    for(int i = 1; i <= len_x; ++i) {
      
    }
    
  }

  cache.insert(std::make_pair(x, y));
  return false;
}

int main() {
  std::scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  simplify(c, d);
  if (!search(a, b)) {
    std::printf("impossible\n");
  }
  return 0;
}
