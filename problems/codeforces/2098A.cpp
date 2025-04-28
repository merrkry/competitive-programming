#include <cstdio>
#include <cstring>

int bucket[15];
char str[15];

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    memset(bucket, 0, sizeof(bucket));
    std::scanf(" %s", str);
    for (int i = 0; i < 10; ++i) {
      bucket[str[i] - '0']++;
    }
    for (int i = 1; i <= 10; ++i) {
      int res;
      for (int j = 10 - i; j <= 9; ++j) {
        if (bucket[j] > 0) {
          --bucket[j];
          res = j;
          break;
        }
      }
      std::printf("%d", res);
    }
    std::printf("\n");
  }
  return 0;
}
