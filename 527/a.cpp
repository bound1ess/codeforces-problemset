#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long ans = 0LL, a, b;
  cin >> a >> b;

  while (b > 0LL) {
    ans += a / b;
    a %= b;
    swap(a, b);
  }

  cout << ans << endl;
  return 0;
}
