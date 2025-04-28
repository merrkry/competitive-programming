#include <algorithm>
#include <cstdio>
#include <utility>

const int N = 2e5 + 5;

int n, m, fa[N], siz[N];

int query(int x) { return fa[x] == x ? x : fa[x] = query(fa[x]); }

void merge(int x, int y) {
  x = query(x), y = query(y);
  if (x == y)
    return;
  if (siz[x] < siz[y])
    std::swap(x, y);
  fa[y] = x;
  siz[x] += siz[y];
}

int main() {
  std::scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    siz[i] = 1;
  }

  for (int i = 1; i <= m; ++i) {
    int x, y;
    std::scanf("%d%d", &x, &y);
    merge(x, y);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, siz[query(i)]);
  }

  std::printf("%d\n", ans);
}
