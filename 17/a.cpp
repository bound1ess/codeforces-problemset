#include <cstdio>
#include <bitset>
#include <cmath>

const int MAX_TOTAL = 1000, MAX_PRIME = 168;

std::bitset<MAX_TOTAL + 1> sieve;
int primes[MAX_PRIME];

inline int build_sieve(int n) {
  int m = sqrt(n), k = 0;
  sieve.set();

  for (int i = 2; i <= m; ++i) {
    if (sieve.test(i)) {
      for (int j = i * i; j <= n; j += i) {
        sieve.set(j, false);
      }
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (sieve.test(i)) {
      primes[k] = i;
      ++k;
    }
  }

  return k;
}

inline bool check(int x, int n) {
  int l = 0, r = n - 1;

  while (l <= r) {
    int m = (l + r) >> 1;

    if (primes[m] == x) {
      return true;
    } else if (primes[m] < x) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return false;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int m = build_sieve(n), count = 0;

  for (int i = 1; i < m - 1; ++i) {
    if (check(primes[i - 1] + primes[i] + 1, m)) {
      ++count;
    }
  }

  printf(count < k ? "NO\n" : "YES\n");
  return 0;
}
