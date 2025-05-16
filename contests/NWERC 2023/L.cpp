#include <cstdio>
#include <set>
#include <string>
#include <utility>

int n, k, total_sunk, pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

std::set<std::pair<int, int>> hit;

char input_buffer[10];

int try_hit(int x, int y) { // 1: already hit, 2: hit, 3: miss, 4: all sunk
  if (std::min(x, y) <= 0 || std::max(x, y) > n) {
    return 3;
  }

  if (hit.find(std::make_pair(x, y)) != hit.end()) {
    return 1;
  }

  hit.insert(std::make_pair(x, y));
  std::printf("%d %d\n", x, y);
  fflush(stdout);

  std::scanf("%s", input_buffer);
  std::string str(input_buffer);

  if (str == "hit") {
    return 2;
  } else if (str == "miss") {
    return 3;
  } else if (str == "sunk") {
    ++total_sunk;
    if (total_sunk == k) {
      return 4;
    }
    return 2;
  }
  std::printf("ERR\n");
  return -1;
}

bool search_ship(int x, int y) {
  int code = try_hit(x, y);
  switch (code) {
  case 2:
    for (int i = 0; i < 4; ++i) {
      for (int mul = 1; mul <= 4; ++mul) {
        code = try_hit(x + pos[i][0] * mul, y + pos[i][1] * mul);
        if (code == 4) {
          return true;
        }
      }
    }
    break;
  case 4:
    return true;
  }
  return false;
}

int main() {
  std::scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++i) {
    for (int j = i % 5 + 1; j <= n; j += 5) {
      bool done = search_ship(i, j);
      if (done) {
        return 0;
      }
    }
  }
  return 0;
}
