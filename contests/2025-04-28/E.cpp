#include <cstdio>
#include <cstring>

const int N = 1e6 + 5;
int n, k, q, len_s, len_t, dist[N][26], cnt[26], pref[N];
char s[N], t[N];

int main() {
  std::scanf("%d%d %s", &n, &k, s);
  len_s = strlen(s);
  for (int i = 0; i < k; ++i)
    cnt[i] = -1;
  for (int i = len_s - 1; i >= 0; --i) {
    for (int j = 0; j < k; ++j) {
      if (s[i] - 'a' == j) {
        cnt[j] = 0;
      } else {
        if (cnt[j] != -1)
          ++cnt[j];
      }
      dist[i][j] = cnt[j] == -1 ? -1 : cnt[j];
      // std::printf("%d ", dist[i][j]);
    }
    // std::printf("\n");
  }
  for (int i = 0; i < len_s; ++i) {
    bool done = false;
    int las = -1;
    for (int j = 0; j < k; ++j) {
      if (dist[i][j] == -1) {
        pref[i] = j;
        done = true;
        break;
      } else if (las == -1 || dist[i][j] > dist[i][las]) {
        las = j;
      }
    }
    if (!done)
      pref[i] = las;
  }
  std::scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    std::scanf(" %s", t);
    len_t = strlen(t);
    int loc = 0, pos = -1; // searching for t[loc], last found at pos
    // for (int j = 0; j < len_s; ++j) {
    //   if (loc < len_t && t[loc] == s[j]) {
    //     // std::printf("Initial match found\n");
    //     ++loc;
    //     pos = j;
    //   }
    // }
    bool not_matched = false;
    for (; loc < len_t; ++loc) {
      ++pos;
      if (pos >= len_s || dist[pos][t[loc] - 'a'] == -1) {
        not_matched = true;
        break;
      }
      pos += dist[pos][t[loc] - 'a'];
    }
    ++pos;
    if (not_matched) {
      std::printf("0\n");
      continue;
    }
    int ans = 0;
    bool done = false; // extra char possible
    while (pos < len_s) {
      int d = dist[pos][pref[pos]];
      if (d == -1) {
        done = true;
        ++ans;
        break;
      } else {
        ++ans;
        pos += d + 1;
      }
    }
    if (!done)
      ++ans;
    std::printf("%d\n", ans);
  }
  return 0;
}
