#include <cstdio>

const int N = 1e6 + 5;

int n, m;
double x[N], y[N], sum_x[N], sum_y[N], sum_xy[N], sum_x2[N];

double get(double *arr, int l, int r) { return arr[r] - arr[l - 1]; }

int main() {
  std::scanf("%d", &n);
  sum_x[0] = sum_y[0] = sum_xy[0] = sum_x2[0] = 0;
  for (int i = 1; i <= n; ++i) {
    std::scanf("%lf%lf", &x[i], &y[i]);
    sum_x[i] = sum_x[i - 1] + x[i];
    sum_y[i] = sum_y[i - 1] + y[i];
    sum_xy[i] = sum_xy[i - 1] + x[i] * y[i];
    sum_x2[i] = sum_x2[i - 1] + x[i] * x[i];
  }

  std::scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int l, r;
    double lambda, X;
    std::scanf("%d%d%lf%lf", &l, &r, &lambda, &X);

    double a1 = get(sum_x2, l, r) + lambda, b1 = get(sum_x, l, r),
           c1 = get(sum_xy, l, r), a2 = get(sum_x, l, r),
           b2 = (r - l + 1 + lambda), c2 = get(sum_y, l, r);

    double K, B;
    if (b1 != 0.0) {
      K = (b2 * c1 / b1 - c2) / (b2 * a1 / b1 - a2);
      B = (c1 - a1 * K) / b1;
    } else {
      K = c1 / a1;
      B = (c2 - a2 * K) / b2;
    }

    std::printf("%.7lf\n", K * X + B);
  }
  return 0;
}
