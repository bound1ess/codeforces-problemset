#include <iostream>

using namespace std;

const int N = 30, M = 123;
long long pow[N];
int a[M];

inline long long solve(int n) {
  long long sum = n * (n + 1ll) / 2ll, remove = 0ll;
  for (int i = 0; i < N; ++i) {
    if (pow[i] <= n) {
      remove += pow[i] * 2ll;
    }
  }
  return sum - remove;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < N; ++i) {
    pow[i] = 1ll << i;
  }
  for (int i = 0; i < t; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < t; ++i) {
    cout << solve(a[i]) << endl;
  }
  return 0;
}
