#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <utility>

typedef unsigned long long ull;

const bool DEBUG = false;
const int N = 2e3 + 5;
ull base = 10007, mod1 = 100000000001647, mod2 = 1e9 + 7;

int n, q, cnt_token, cnt_var, cnt_tmp;
int origin[N], tmp_seq[N];
char input_buffer[N];
std::map<std::string, int> tokens;
std::map<int, int> vars;
std::set<std::pair<ull, ull>> hashes;

int main() {
  std::scanf("%d", &n);
  std::string tmp_str;
  for (int i = 1; i <= n; ++i) {
    std::scanf("%s", input_buffer);
    std::string input_string = input_buffer;
    int len = std::strlen(input_buffer);
    if (len == 1 && std::isalpha(input_buffer[0])) {
      origin[i] = -input_buffer[0];
    } else {
      auto it = tokens.find(input_string);
      if (it == tokens.end()) {
        tokens[input_string] = ++cnt_token;
        origin[i] = cnt_token;
      } else {
        origin[i] = it->second;
      }
    }
  }

  for (int l = 1; l <= n; ++l) {
    vars.clear();
    ull hash1 = 0, hash2 = 0, now = 0;
    cnt_var = 0;
    for (int r = l; r <= n; ++r) {
      if (origin[r] > 0) { // token
        now = origin[r];
      } else { // var
        auto it = vars.find(-origin[r]);
        if (it == vars.end()) {
          vars[-origin[r]] = ++cnt_var;
          now = -cnt_var;
        } else {
          now = -it->second;
        }
      }

      now += N;
      hash1 = (hash1 * base + now) % mod1;
      hash2 = (hash2 * base + now) % mod2;

      hashes.insert(std::make_pair(hash1, hash2));
    }
  }

  if (DEBUG)
    std::printf("!\n");

  std::scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int num_tokens;
    std::scanf("%d", &num_tokens);
    ull hash1 = 0, hash2 = 0, now = 0;
    bool new_token = false;
    vars.clear();
    cnt_var = 0;

    for (int j = 1; j <= num_tokens; ++j) {
      std::scanf("%s", input_buffer);
      std::string input_string = input_buffer;
      // std::printf("%s\n", input_buffer);
      int len = std::strlen(input_buffer);

      if (len == 1 && std::isalpha(input_buffer[0])) {
        auto it = vars.find(input_buffer[0]);
        if (it == vars.end()) {
          vars[input_buffer[0]] = ++cnt_var;
          now = -cnt_var;
        } else {
          now = -it->second;
        }
      } else {
        auto it = tokens.find(input_string);
        if (it == tokens.end()) {
          new_token = true;
        } else {
          now = it->second;
        }
      }

      if (DEBUG)
        std::printf("%c ", input_buffer[0]);

      now += N;
      hash1 = (hash1 * base + now) % mod1;
      hash2 = (hash2 * base + now) % mod2;
    }

    if (DEBUG)
      std::printf("| %d \n", new_token);

    if (!new_token &&
        hashes.find(std::make_pair(hash1, hash2)) != hashes.end()) {
      std::printf("yes\n");
    } else {
      std::printf("no\n");
    }
  }
}
