#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>

int n;
std::map<int, int> cache;
void clear() {
  fflush(stdin);
  fflush(stdout);
}

int query(int p) {
  if (cache.find(p) != cache.end()) {
    return cache.find(p)->second;
  }
  std::printf("? %d\n", p);
  clear();
  int res;
  std::scanf("%d", &res);
  clear();
  cache.insert(std::make_pair(p, res));
  return res;
}

double answer(int x, int y, int z) {
  auto vals = std::vector<int>{query(x), query(y), query(z)};
  std::sort(vals.begin(), vals.end());
  return std::sqrt(vals[1] - vals[0]) + std::sqrt(vals[2] - vals[1]) +
         std::sqrt(vals[2] - vals[0]);
}

int ans;
double maxT = -1.0;

void try_answer(int p) {
  if (1 < p && p < n && answer(1, n, p) > maxT) {
    ans = p;
    maxT = answer(1, n, p);
    // std::printf("DEBUG: %d %lf\n", ans, maxT);
  }
}

int main() {
  std::scanf("%d", &n);
  clear();

  int target = query(1) + query(n), L = 1, R = n, Mid;

  while (L <= R) {
    Mid = (L + R) / 2;
    int val = query(Mid);
    try_answer(Mid);
    if (val * 2 <= target) {
      L = Mid + 1;
    } else {
      R = Mid - 1;
    }
  }

  try_answer(Mid - 2);
  try_answer(Mid - 1);
  try_answer(Mid);
  try_answer(Mid + 1);
  try_answer(Mid + 2);

  // std::printf("Mid: %d\n", Mid);

  std::printf("! %d %d %d", 1, n, ans);
  clear();

  return 0;
}
