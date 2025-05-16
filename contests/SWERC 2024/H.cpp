#include <iostream>
#include <map>
#include <string>

int n;
std::map<std::string, int> cnt;

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::string str;
    std::cin >> str;
    auto it = cnt.find(str);
    if (it != cnt.end()) {
      cnt[str]++;
    } else {
      cnt[str] = 1;
    }
  }
  auto mark = cnt.begin();
  for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    if (it->second > mark->second) {
      mark = it;
    }
  }
  std::cout << mark->first << std::endl;
  return 0;
}
