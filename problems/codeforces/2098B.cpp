#include <algorithm>
#include <cstdio>

typedef long long ll;

const int N = 1e5 + 5;

int n, k;
ll a[N], sum[N];

ll calc(int pos, int left, int right) {
  ll left_cnt = pos - 1 - left, right_cnt = n - pos - right;
  return left_cnt * a[pos] - (sum[pos - 1] - sum[left]) +
         (sum[n - right] - sum[pos]) - right_cnt * a[pos];
}

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%lld", &a[i]);
    }

    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + a[i];
    }

    ll ans = 1LL << 62;
    int right = k, cnt = 0;
    for (int i = 1; i <= n; ++i) {
#define left (k - right)
      if (right > 0 && left <= i - 2 &&
          calc(i, left, right) > calc(i, left + 1, right - 1)) {
        --right;
      }
      ll now = calc(i, left, right);
      if (now < ans) {
        ans = now;
        cnt = 1;
      } else if (now == ans) {
        ++cnt;
      }
      // std::printf("DEBUG: %d %d %lld\n", i, right, now);
    }

    std::printf("%d\n", cnt);
  }

  return 0;
}
