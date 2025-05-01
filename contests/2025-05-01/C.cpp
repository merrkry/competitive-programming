#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <utility>

typedef long long ull;
const int N = 2e5 + 5;

int n, n_val, a[N], b[N], cnt[N], lst[N], pre[N];
bool pressed[N];

std::multimap<int, int, std::greater<int>> adj;

void press(int pos) {
  // std::printf("Pressed %d\n", pos);
  pressed[pos] = 1;
  cnt[a[pos]] -= 1;
  if (pos > 1 && !pressed[pos - 1])
    adj.insert(std::make_pair(a[pos - 1], pos - 1));
  if (pos < n && !pressed[pos + 1])
    adj.insert(std::make_pair(a[pos + 1], pos + 1));
}

// void print_arr(int *arr) {
//   for (int j = 1; j <= n; ++j) {
//     std::printf("%d ", arr[j]);
//   }
//   std::printf("\n");
// }

int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    std::scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      std::scanf("%d", a + i);
      b[i] = a[i];
    }

    adj.clear();
    for (int i = 1; i <= n; ++i) {
      lst[i] = pre[i] = cnt[i] = 0;
      pressed[i] = false;
    }

    std::sort(b + 1, b + n + 1);
    n_val = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++i) {
      a[i] = std::lower_bound(b + 1, b + n_val + 1, a[i]) - b;

      cnt[a[i]] += 1;
      if (!lst[a[i]]) {
        lst[a[i]] = i;
      } else {
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
      }
    }

    int curr = n_val, las_pos = lst[curr], ans = 0;
    for (int i = 1; i <= n; ++i) {
      // for (auto it = adj.begin(); it != adj.end(); ++it) {
      //   std::printf("Adj: %d %d\n", it->first, it->second);
      // }
      // std::printf("\n");

      if (cnt[curr] == 0) {
        --curr;
        las_pos = lst[curr];
      }

      while (!adj.empty() && pressed[adj.begin()->second])
        adj.erase(adj.begin());

      auto candidate = adj.begin();
      if (candidate != adj.end() && candidate->first == curr) {
        press(candidate->second);
        adj.erase(candidate);
        continue;
      }

      // std::printf("New clone created\n");

      while (pressed[las_pos]) {
        las_pos = pre[las_pos];
      }
      press(las_pos);
      ++ans;
    }

    std::printf("%d\n", ans);
  }
}
