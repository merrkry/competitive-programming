#include <cstdio>
#include <vector>

const int N = 1e4 + 5;

int n, a[N];
bool not_prime[N];
std::vector<int> pri;

int count(int x, int p) {
  int ans = 0;
  while (x % p == 0) {
    ++ans;
    x /= p;
  }
  return ans;
}

int main() {
  for (int i = 2; i <= 1e4; ++i) {
    if (!not_prime[i])
      pri.push_back(i);
    for (auto p : pri) {
      if (i * p > 1e4)
        break;
      not_prime[i * p] = true;
      if (i % p == 0)
        break;
    }
  }
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", a + i);
    }

    int c = 0; // find first a_c != a_1
    for (int i = 2; i <= n; ++i) {
      if (a[1] != a[i]) {
        c = i;
        break;
      }
    }
    if (c == 0) {
      std::printf("No\n");
      continue;
    }

    int d = 0; // prime factor that differs
    for (int p : pri) {
      if (count(a[1], p) != count(a[c], p)) {
        d = p;
        break;
      }
    }

    std::printf("Yes\n");
    for (int i = 1; i <= n; ++i) {
      int ans = i == 1 || count(a[1], d) == count(a[i], d) ? 1 : 2;
      std::printf("%d ", ans);
    }
    std::printf("\n");
  }
}
