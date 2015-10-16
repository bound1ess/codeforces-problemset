#include <iostream>

using namespace std;

int main() {
  long long n, ans = 1LL;
  cin >> n;
  for (long long i = 2LL; i * i <= n; ++i) {
    if (n % i == 0LL) {
      ans *= i;
      while (n % i == 0LL) {
        n /= i;
      }
    }
  }
  if (n > 1LL) {
    ans *= n;
  }
  cout << ans << endl;
  return 0;
}
