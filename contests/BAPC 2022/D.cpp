#include <cstdio>
#include <cstring>

char buffer[20];

int n;

void flush() {
  fflush(stdin);
  fflush(stdout);
}

bool query(int L, int R) {
  flush();
  std::printf("? %d %d\n", L - 1, R);
  flush();
  std::scanf("%s", buffer);
  flush();
  return strcmp(buffer, "absent") == 0;
}

int main() {
  std::scanf("%d", &n);
  flush();

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = 0;
    for (int j = i; j <= n; ++j) {
      if (query(i, j)) {
        tmp = j;
        break;
      }
    }
    if (tmp != 0) {
      ++ans;
      i = tmp;
    }
  }

  std::printf("%d\n", ans);
  flush();

  return 0;
}
