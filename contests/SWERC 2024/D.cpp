#include <algorithm>
#include <cstdio>
#include <set>

typedef long long ll;
const int N = 2e5 + 5;

int n;
ll h[N], h2[N], rev[N];
std::set<int> st;

int main() {
  std::scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    std::scanf("%lld", h + i);
    h2[i] = h[i];
  }
  std::sort(h2 + 1, h2 + n + 1);
  for (int i = 1; i <= n; ++i) {
    int rank = std::lower_bound(h2 + 1, h2 + n + 1, h[i]) - h2;
    rev[rank] = i;
  }
  ll ans = 0;
  st.insert(rev[n]);
  for (int i = n - 1; i >= 1; --i) {
    auto it = st.upper_bound(rev[i]);
    if (it != st.end()) {
      if (it == st.begin()) {
        ans += (*it - rev[i]);
      } else {
        auto next = it, pre = next;
        --pre;
        ans += std::min(rev[i] - *pre, *next - rev[i]);
      }
    } else {
      auto las = --st.end();
      ans += (rev[i] - *las);
    }
    st.insert(rev[i]);
  }
  std::printf("%lld\n", ans);
  return 0;
}
