#include <algorithm>
#include <cstdio>

typedef long long ll;
const int N = 4e5 + 5;
const int M = 6e6 + 6; // 4e5-th prime number is roughly 5.8e6

int n, n_p, a[N], p[N];
ll sum_p[N];
bool not_prime[M];

int main() {
  for (int i = 2; i < M; ++i) {
    if (!not_prime[i]) {
      p[++n_p] = i;
    }
    for (int j = 1; j <= n_p; ++j) {
      int prime = p[j];
      if ((ll)i * prime >= M)
        break;
      not_prime[i * prime] = true;
      if (i % prime == 0)
        break;
    }
  }
  for (int i = 1; i < N; ++i) {
    sum_p[i] = sum_p[i - 1] + p[i];
  }

  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d", &n);
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", a + i);
      tot += a[i];
    }
    std::sort(a + 1, a + n + 1);
    if (sum_p[n] <= tot) {
      std::printf("0\n");
    } else {
      int ans = 0;
      for (int i = 1; i < n; ++i) {
        tot -= a[i];
        if (sum_p[n - i] <= tot) {
          ans = i;
          break;
        }
      }
      if (!ans)
        ans = n - 1;
      std::printf("%d\n", ans);
    }
  }
}
