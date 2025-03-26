#include <cstdio>
typedef long long ll;
const int N = 1e7 + 5;
int pri[N], minp[N], cntp[N];
ll sum[N];
int main() {
  for (int i = 2; i <= 1e7; ++i) {
    if (minp[i] == 0) {
      pri[++pri[0]] = i;
      minp[i] = i;
      cntp[i] = 1;
    }
    for (int j = 1; j <= pri[0]; ++j) {
      if (i * pri[j] > 1e7) {
        break;
      }
      int k1 = i * pri[j];
      minp[k1] = pri[j];
      int k2 = k1 / minp[k1];
      cntp[k1] = minp[k2] == minp[k1] ? cntp[k2] : cntp[k2] + 1;
      if (i % pri[j] == 0) {
        break;
      }
    }
    sum[i] = sum[i - 1] + cntp[i];
  }
  // for (int i = 1; i <= 30; ++i) {
  //   std::printf("%d %d %d\n", i, minp[i], cntp[i]);
  // }
  // std::printf("\n");
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n;
    std::scanf("%d", &n);
    std::printf("%lld\n", sum[n]);
  }
  return 0;
}
