#include <algorithm>
#include <cstdio>

typedef long long ll;
const int N = 2e5 + 5;
const ll INF = 1LL << 62;

int n, left[N], right[N];
ll k, a[N], val[N], back_max[N], forth_max[N];
bool s[N];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d%lld", &n, &k);
    bool exist_unknown = false;
    for (int i = 1; i <= n; ++i) {
      char c;
      std::scanf(" %c", &c);
      s[i] = c - '0';
      exist_unknown |= !s[i];
    }
    for (int i = 1; i <= n; ++i) {
      std::scanf("%lld", &a[i]);
    }

    int las = 0;
    for (int i = 1; i <= n; ++i) {
      left[i] = las;
      if (!s[i])
        las = i;
    }
    las = n + 1;
    for (int i = n; i >= 1; --i) {
      right[i] = las;
      if (!s[i])
        las = i;
    }

    back_max[0] = -INF;
    for (int i = 1; i <= n; ++i) {
      if (!s[i]) {
        back_max[i] = -INF;
      } else {
        back_max[i] = a[i] + std::max(back_max[i - 1], 0LL);
      }
    }
    forth_max[n + 1] = -INF;
    for (int i = n; i >= 1; --i) {
      if (!s[i]) {
        forth_max[i] = -INF;
      } else {
        forth_max[i] = a[i] + std::max(forth_max[i + 1], 0LL);
      }
    }

    ll single_max = -INF;
    for (int i = 1; i <= n; ++i) {
      if (!s[i])
        continue;
      single_max = std::max(single_max, std::max(back_max[i], forth_max[i]));
      if (back_max[i] > -INF && forth_max[i] > -INF) {
        single_max = std::max(single_max, back_max[i] - a[i] + forth_max[i]);
      }
    }

    if (single_max > k) {
      std::printf("No\n");
      continue;
    }

    if (!exist_unknown) {
      if (single_max == k) {
        std::printf("Yes\n");
        for (int i = 1; i <= n; ++i) {
          std::printf("%lld ", a[i]);
        }
        std::printf("\n");
      } else {
        std::printf("No\n");
      }
      continue;
    }

    ll max_val = -INF, pos = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i]) {
        continue;
      }
      val[i] = 0;
      ll max_sum = -INF, sum = 0;
      for (int j = i - 1; j > left[i]; --j) {
        sum += a[j];
        max_sum = std::max(max_sum, sum);
      }
      if (max_sum > 0)
        val[i] += max_sum;
      max_sum = -INF, sum = 0;
      for (int j = i + 1; j < right[i]; ++j) {
        sum += a[j];
        max_sum = std::max(max_sum, sum);
      }
      if (max_sum > 0)
        val[i] += max_sum;
      // std::printf("DEBUG: %d %d %lld\n", left[i], right[i], val[i]);
      if (val[i] > max_val) {
        pos = i;
        max_val = val[i];
      }
    }

    std::printf("Yes\n");
    for (int i = 1; i <= n; ++i) {
      ll ans;
      if (s[i]) {
        ans = a[i];
      } else if (i != pos) {
        ans = -1e18;
      } else {
        ans = k - max_val;
      }
      std::printf("%lld ", ans);
    }
    std::printf("\n");
  }
  return 0;
}
