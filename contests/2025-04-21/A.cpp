#include <cstdio>
#include <set>
int main() {
  int T;
  std::scanf("%d", &T);
  while (T--) {
    int n;
    std::scanf("%d", &n);
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
      int tmp;
      std::scanf("%d", &tmp);
      st.insert(tmp);
    }
    std::printf("%d\n", (int)st.size());
  }
  return 0;
}
