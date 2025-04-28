#include <cstdio>
#include <set>
#include <utility>

typedef long long ll;
const int N = 3e2 + 5;

int n, n_cards[3];
ll num;
bool dp[2][2][N][N][N];
std::multiset<std::pair<char, int>> cards[3]; // +0, +1, x0

void add_card(int type, char o, int x) {
  ++n_cards[type];
  cards[type].insert(std::make_pair(o, x));
}

void prepare() {
  dp[0][1][0][0][0] = 1;
  dp[1][0][0][0][0] = 1;
  for (int i = 0; i <= n_cards[0]; ++i) {     // card 0
    for (int j = 0; j <= n_cards[1]; ++j) {   // card 1
      for (int k = 0; k <= n_cards[2]; ++k) { // card 2
        if (i == 0 && j == 0 && k == 0)
          continue;
        for (int v = 0; v <= 1; ++v) { // value after operation
          for (int w = 0; w <= 1; ++w) {
            bool res = 1;
            if (i >= 1) {
              res &= (dp[w ^ 1][v][i - 1][j][k] ^ 1);
            }
            if (j >= 1) {
              res &= (dp[w ^ 1][v ^ 1][i][j - 1][k] ^ 1);
            }
            if (k >= 1) {
              res &= (dp[w ^ 1][0][i][j][k - 1] ^ 1);
            }
            dp[w][v][i][j][k] = res;
            // std::printf("dp[%d][%d][%d][%d][%d]=%d\n", w, v, i, j, k,
            //             dp[w][v][i][j][k]);
          }
        }
      }
    }
  }
}

int choose(int who) {
  if (n_cards[0] > 0 &&
      dp[who][num % 2][n_cards[0] - 1][n_cards[1]][n_cards[2]])
    return 0;
  if (n_cards[1] > 0 &&
      dp[who][(num % 2) ^ 1][n_cards[0]][n_cards[1] - 1][n_cards[2]])
    return 1;
  if (n_cards[2] > 0 && dp[who][0][n_cards[0]][n_cards[1]][n_cards[2] - 1])
    return 2;
  // std::printf("FAIL!\n");
  return -1;
}

void flush() {
  std::fflush(stdin);
  std::fflush(stdout);
}

int get_card_type(char o, int x) {
  if (o == '+' && x % 2 == 1)
    return 1;
  if (o == '*' && x % 2 == 0)
    return 2;
  return 0;
}

void apply_card(char o, int x) {
  if (o == '+') {
    num += x;
  } else {
    num *= x;
  }
  int type = get_card_type(o, x);
  cards[type].erase(cards[type].find(std::make_pair(o, x)));
  n_cards[type]--;
}

void play_card(int type) {
  auto candidate = cards[type].begin();
  // if (candidate == cards[type].end())
  //   std::printf("PANIC");
  std::printf("%c %d\n", candidate->first, candidate->second);
  apply_card(candidate->first, candidate->second);
  flush();
}

void accept_card() {
  char o;
  int x;
  std::scanf(" %c %d", &o, &x);
  // std::printf("LOG: card accpeted %c %d\n", o, x);
  flush();
  apply_card(o, x);
}

void play() {
  int initial_choice = choose(0), me = 0;
  if (initial_choice == -1) {
    std::printf("you\n");
    flush();
    me = 1;
    accept_card();
  } else {
    std::printf("me\n");
    play_card(initial_choice);
  }
  flush();

  int who = 1;
  while (true) {
    if (n_cards[0] == 0 && n_cards[1] == 0 && n_cards[2] == 0) {
      return;
    }

    if (who == me) {
      play_card(choose(me));
    } else {
      accept_card();
    }

    who ^= 1;
  }
}

int main() {
  std::scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    char o;
    int x;
    std::scanf(" %c %d", &o, &x);
    add_card(get_card_type(o, x), o, x);
  }
  prepare();
  std::scanf("%lld", &num);
  flush();
  play();
  return 0;
}
