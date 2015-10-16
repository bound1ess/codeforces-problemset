#include <iostream>

using namespace std;

int main() {
  unsigned long long l, r;
  cin >> l >> r;
  if (l % 2LL == 1LL) {
    ++l;
  }
  if (r > 2LL && r - 2LL >= l) {
    cout << l << ' ' << (l + 1) << ' ' << (l + 2) << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
