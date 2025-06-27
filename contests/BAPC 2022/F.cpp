#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>

typedef unsigned long long ull;

const int N = 1e3 + 5;

std::map<char, double> basic_direction = {
    {'N', 0}, {'E', 90}, {'S', 180}, {'W', 270}};

double calc_degree(std::string &s) {
  int len = s.length();
  switch (len) {
  case 1:
    return basic_direction[s[0]];
  default:
    char ch0 = s[len - 2], ch1 = s[len - 1];
    if ((ch0 == 'S' && ch1 == 'E') || (ch0 == 'N' && ch1 == 'W')) {
      std::swap(ch0, ch1);
    }

    // ull den = 0, num = 1;
    // for (int i = 0; i < std::min(len - 1, 60); ++i) {
    //   den = (den << 1) + static_cast<int>(s[i] == ch1);
    //   num <<= 1;
    // }

    // return basic_direction[ch0] + static_cast<double>(den) / num * 90;
    double offset = 45, now = 45;
    for (int i = len - 3; i >= 0; --i) {
      double mul = s[i] == ch0 ? -1.0 : 1.0;
      now /= 2.0;
      offset += now * mul;
    }

    return basic_direction[ch0] + offset;
  }
}

int main() {
    std::string x, y;
  std::cin >> x >> y;

  double d = std::abs(calc_degree(y) - calc_degree(x)),
         ans = std::min(d, 360 - d);

  std::printf("%.8lf", ans);
  return 0;
}
