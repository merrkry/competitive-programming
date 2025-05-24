#include <cstdio>
#include <set>

const int N = 1e5 + 5;

struct HorizontalSegment {
  int start, end, height;

  bool operator<(const HorizontalSegment &other) const {
    if (height != other.height)
      return height < other.height;
    if (start != other.start)
      return start < other.start;
    return end != other.end;
  }
} h[N * 2];

struct VerticalSegment {
  int start, end, pos;
  bool operator<(const VerticalSegment &other) const {
    if (pos != other.pos)
      return pos < other.pos;
    if (start != other.start)
      return start < other.start;
    return end < other.end;
  }
} v[N * 2];

std::set<HorizontalSegment> st;

int main() {

  
  return 0;
}
