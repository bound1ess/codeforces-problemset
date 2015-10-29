#include <iostream>
#include <set>

using namespace std;
set<long long> prime_set;

const int N = 1234567;
bool prime[N];

inline void build() {
  for (int i = 2; i < N; ++i) {
    prime[i] = true;
  }
  for (int i = 2; i * i < N; ++i) {
    if (prime[i]) {
      for (int j = i * i; j < N; j += i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i < N; ++i) {
    if (prime[i]) {
      prime_set.insert(i * 1LL * i);
    }
  }
}

int main() {
  build();
  ios_base::sync_with_stdio(false);
  int n;
  long long x;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cout << (prime_set.find(x) != prime_set.end() ? "YES" : "NO") << '\n';
  }
  return 0;
}
