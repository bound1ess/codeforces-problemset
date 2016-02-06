#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, t, d;
  int n, k = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (i == 0) {
      t = s;
    } else if (s == t) {
      ++k;
    } else {
      d = s;
    }
  }
  cout << (n - k < k ? t : d) << endl;
  return 0;
}
