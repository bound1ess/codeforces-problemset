#include <iostream>
#include <cmath>

using namespace std;

inline long long square(long long x) {
  return x * x;
}

int main() {
  long long r, x1, y1, x2, y2, ans, dist, tmp, step;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  step = square(r) * square(2);
  dist = square(x1 - x2) + square(y1 - y2);
  tmp = (-1 + step + dist) / step;
  ans = sqrt((double) tmp);
  while (square(ans) < tmp) {
    ++ans;
  }
  while (ans > 0 && square(-1 + ans) >= tmp) {
    --ans;
  }
  cout << ans << endl;
  return 0;
}
