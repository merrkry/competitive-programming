#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    double p, r, y;
    std::scanf("%lf%lf%lf", &p, &r, &y);
    std::vector<double> points = {-p, (y + r - p) / 2, (y - r - p) / 2, 0};
    std::sort(points.begin(), points.end());
    double w = (points[0] + points[3]) / 2;
    std::printf("%.10lf %.10lf %.10lf %.10lf\n", (y + r - p) / 2 - w, p + w,
                (y - r - p) / 2 - w, w);
  }
  return 0;
}
