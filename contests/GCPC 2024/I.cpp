#include <cstdio>

typedef long long ll;

const int N = 4e3 + 5;

int n, w, n_waves;

struct wave {
  int p, l, a;
} waves[N];

int main() {
  std::scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; ++i) {
    char op;
    std::scanf(" %c", &op);
    if (op == '!') {
      ++n_waves;
      std::scanf("%d%d%d", &waves[n_waves].p, &waves[n_waves].l,
                 &waves[n_waves].a);
    } else {
      int pos;
      std::scanf("%d", &pos);
      ll ans = 0;
      for (int j = 1; j <= n_waves; ++j) {
        if (pos < waves[j].p || pos > waves[j].p + waves[j].l - 1) {
          continue;
        }

        int val;
        switch ((pos - waves[j].p) % 4) {
        case 0:
          val = waves[j].a;
          break;
        case 1:
          val = 0;
          break;
        case 2:
          val = -waves[j].a;
          break;
        case 3:
          val = 0;
          break;
        }

        ans += val;
      }
      std::printf("%lld\n", ans);
    }
  }
  return 0;
}
