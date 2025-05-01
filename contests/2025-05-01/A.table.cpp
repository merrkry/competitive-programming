#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>

const int N = 5e2 + 5;

int n = 10, p[N];

std::set<int> vals;

int main() {
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      p[j] = j;
    }
    vals.clear();
    vals.insert(0);
    while (std::next_permutation(p + 1, p + i + 1)) {
      int sum = 0;
      for (int j = 1; j <= i; ++j) {
        sum += std::abs(p[j] - j);
        // std::printf("%d ", p[j]);
      }
      // std::printf("\n");
      vals.insert(sum);
    }
    std::printf("%d %d\n", i, (int)vals.size());
  }
  return 0;
}
