#include <cstdio>
#include <cstdlib>

typedef long long ull;
const int N = 5e2 + 5;

int n;
ull ans[N];

int main() {
  ans[1] = 1;
  ans[2] = 2;
  for (int i = 3; i <= 500; ++i) {
    ans[i] = ans[i - 1] + i / 2;
  }
  std::scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    std::scanf("%d", &x);
    std::printf("%lld\n", ans[x]);
  }
  return 0;
}
