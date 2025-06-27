#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>

const int N = 1e5 + 5;

int n, out[N];

std::vector<std::pair<int, int>> g[N];
std::vector<int> uniq_in[N];
std::vector<int> loop;

std::vector<std::tuple<int, int, int>> input;

bool vis[N], in_loop[N];

bool verify_subtree(int now) {
  int cnt = 0;

  for (auto edge : g[now]) {
    int v = edge.first, h = edge.second;
    if (in_loop[v]) {
      continue;
    }

    ++cnt;
    bool subtree_res = verify_subtree(v);
    if (!subtree_res) {
      return false;
    }

    uniq_in[now].push_back(h);

    out[v] = now;
  }

  std::sort(uniq_in[now].begin(), uniq_in[now].end());
  int uniq_num = std::unique(uniq_in[now].begin(), uniq_in[now].end()) -
                 uniq_in[now].begin();
  return uniq_num == cnt;
}

int find_loop(int now, int prev) {
  if (vis[now]) {
    return now;
  }

  vis[now] = true;

  for (auto edge : g[now]) {
    int v = edge.first;
    if (v == prev) {
      continue;
    }
    int l = find_loop(v, now);
    if (l != 0) {
      in_loop[now] = true;
      loop.push_back(now);
      return now == l ? 0 : l;
    }
  }

  return 0;
}

bool verify_loop(bool seq) {
  for (int i = 0; i < loop.size(); ++i) {
    int u = loop[i], target;
    if (seq) {
      target = i == loop.size() - 1 ? loop[0] : loop[i + 1];
    } else {
      target = i == 0 ? loop[loop.size() - 1] : loop[i - 1];
    }
    out[u] = target;
    for (auto edge : g[u]) {
      int v = edge.first, h = edge.second;
      if (v != target) {
        continue;
      }

      if (std::find(uniq_in[u].begin(), uniq_in[u].end(), h) !=
          uniq_in[u].end()) {
        return false;
      }
    }
  }
  return true;
}

void print_answer() {
  for (auto edge : input) {
    auto [u, v, h] = edge;
    printf("%d ", out[u] == v ? u : v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int u, v, h;
    scanf("%d%d%d", &u, &v, &h);
    g[u].push_back({v, h});
    g[v].push_back({u, h});
    input.push_back({u, v, h});
  }

  find_loop(1, 0);

  for (int u : loop) {
    if (!verify_subtree(u)) {
      printf("impossible\n");
      return 0;
    }
  }

  // std::printf("Subtree verified\n");

  if (verify_loop(true)) {
    print_answer();
  } else if (verify_loop(false)) {
    print_answer();
  } else {
    printf("impossible\n");
    return 0;
  }

  return 0;
}
