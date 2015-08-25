#include <iostream>

using namespace std;

int main() {
  int n, m, a = 1, b;
  long long sum = 0ll;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> b;
    sum += (a <= b ? b - a : n - a + b);
    a = b;
  }

  cout << sum << endl;
  return 0;
}
