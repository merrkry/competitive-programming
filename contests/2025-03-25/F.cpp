#include <cmath>
#include <cstdio>
#include <utility>
const int N = 2e3 + 5;
const int M = 998244353;
int n, m, d;
int sig[N][N], tot[N][N], sig_sum[N][N], tot_sum[N][N];
bool mat[N][N];
char input_char[N];

bool is_valid(int i1, int i2, int j1, int j2) {
  return std::sqrt((i1 - i2) * (i1 - i2) + (j1 - j2) * (j1 - j2)) <= d;
}

int calc_sig(int row, int col1, int col2) {
  if (col1 > col2)
    std::swap(col1, col2);
  return ((long long)sig_sum[row][col2] - sig_sum[row][col1 - 1] + M) % M;
}
int calc_tot(int row, int col1, int col2) {
  if (col1 > col2)
    std::swap(col1, col2);
  return ((long long)tot_sum[row][col2] - tot_sum[row][col1 - 1] + M) % M;
}

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%s", input_char);
      for (int j = 1; j <= m; ++j) {
        mat[i][j] = input_char[j - 1] == 'X';
      }
    }

    for (int i = 1; i <= n; ++i) {
      // from the level below
      if (i == 1) {
        for (int j = 1; j <= m; ++j) {
          sig[i][j] = mat[i][j];
          sig_sum[i][j] = ((long long)sig_sum[i][j - 1] + sig[i][j] + M) % M;
        }
      } else {
        for (int j = 1, left = 1, right = 1; j <= m; ++j) {
          while (!is_valid(i, i - 1, j, left))
            ++left;
          while (right < m && is_valid(i, i - 1, j, right + 1))
            ++right;
          sig[i][j] = mat[i][j] ? calc_sig(i - 1, left, right) : 0;
          sig_sum[i][j] = ((long long)sig_sum[i][j - 1] + sig[i][j] + M) % M;
        }
      }
      // from the same level
      for (int j = 1, left = 1, right = 1; j <= m; ++j) {
        while (!is_valid(i, i, j, left))
          ++left;
        while (right < m && is_valid(i, i, j, right + 1))
          ++right;
        tot[i][j] = calc_tot(i - 1, left, right);
        tot_sum[i][j] = ((long long)tot_sum[i][j - 1] + tot[i][j]) % M;
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        std::printf("%d ", sig[i][j]);
      }
      std::printf("\n");
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        std::printf("%d ", tot[i][j]);
      }
      std::printf("\n");
    }

    printf("%d\n", tot_sum[n][m]);
  }
  return 0;
}
