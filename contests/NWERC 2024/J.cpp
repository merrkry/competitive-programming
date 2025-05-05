#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 5e2 + 5;

int n;

struct crane {
  int x, y, h, id, ans;
} cranes[N];

int dist(crane c1, crane c2) {
  int dx = c1.x - c2.x, dy = c1.y - c2.y;
  return (int)std::sqrt(dx * dx + dy * dy);
}

int main() {
  std::scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    std::scanf("%d%d%d", &cranes[i].x, &cranes[i].y, &cranes[i].h);
    cranes[i].id = i;
  }
  std::sort(cranes + 1, cranes + n + 1,
            [](crane c1, crane c2) { return c1.h > c2.h; });
  for (int i = 1; i <= n; ++i) {
    int len = cranes[i].h;
    for (int j = 1; j < i; ++j) {
      len = std::min(dist(cranes[i], cranes[j]), len);
    }
    cranes[i].ans = len;
  }
  std::sort(cranes + 1, cranes + n + 1,
            [](crane c1, crane c2) { return c1.id < c2.id; });
  for (int i = 1; i <= n; ++i) {
    std::printf("%d\n", cranes[i].ans);
  }
  return 0;
}
