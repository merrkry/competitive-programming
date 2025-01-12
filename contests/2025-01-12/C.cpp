#include <algorithm>
#include <bits/stdc++.h>

const int N = 1e3 + 5;
const long long M = 1e15;

int n, m;
long long a[N][N], b[N][N], sumX[N], sumY[N];
char r[N << 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    printf("T = %d\n", T);
    scanf("%d%d%s", &n, &m, r);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%lld", &a[i][j]);
        b[i][j] = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      sumX[i] = 0;
      for (int j = 1; j <= m; ++j) {
        sumX[i] += a[i][j];
      }
    }
    for (int j = 1; j <= m; ++j) {
      sumY[j] = 0;
      for (int i = 1; i <= n; ++i) {
        sumY[j] += a[i][j];
      }
    }

    r[0] = r[1];
    r[n + m - 1] = (r[n + m - 2] == 'D') ? 'R' : 'D';
    long long L = std::max(*std::max_element(sumX + 1, sumX + n + 1),
                           *std::max_element(sumY + 1, sumY + m + 1)),
              R = M * std::max(n, m), Mid, sX = 0, sY = 0;
    while (L < R) {
      Mid = (L + R) / 2;
      printf("Mid = %lld\n", Mid);
      bool possible = true;
      for (int i = 0, x = 1, y = 1; i <= n + m - 2;
           ++i, x += (r[i] == 'R'), y += (r[i] == 'D')) {
        if (r[i + 1] == 'D') {
          b[x][y] = Mid - sumY[y] - sX;

          if (b[x][y] < -M) {
            possible = false;
            L = M + 1;
            break;
          }
          if (b[x][y] > M) {
            possible = false;
            R = M - 1;
            break;
          }

          sX = 0;
          sY += b[x][y];
        } else {
          b[x][y] = Mid - sumX[x] - sY;

          if (b[x][y] < -M) {
            possible = false;
            L = M + 1;
            break;
          }
          if (b[x][y] > M) {
            possible = false;
            R = M - 1;
            break;
          }

          sX += b[x][y];
          sY = 0;
        }
      }

      long long SX = 0, SY = 0;
      for (int i = 1; i <= n; ++i) {
        SX += b[i][m];
      }
      for (int j = 1; j <= m; ++j) {
        SY += b[n][j];
      }

      if (possible) {
        if (r[n + m - 2] == 'D') {
          if (SY > Mid) {
            L = Mid + 1;
            possible = false;
            break;
          }
          if (SY < Mid) {
            R = Mid - 1;
            possible = false;
            break;
          }
        } else {
          if (SX > Mid) {
            L = Mid + 1;
            possible = false;
            break;
          }
          if (SX < Mid) {
            R = Mid - 1;
            possible = false;
            break;
          }
        }
      }

      if (possible) {
        for (int i = 1; i <= n; ++i) {
          for (int j = 1; j <= m; ++j) {
            printf("%lld ", b[i][j]);
          }
          printf("\n");
        }
        break;
      }
    }
  }
  return 0;
}
