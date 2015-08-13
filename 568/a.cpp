#include <cstdio>

const int N = 7000000;
bool sieve[N];
int sieve_sum[N], palind_sum[N];

inline bool is_palindrome(int n) {
  int reversed = 0;
  for (int i = n; i > 0; i /= 10) {
    reversed = reversed * 10 + i % 10;
  }
  return reversed == n;
}

inline void build_sieve() {
  for (int i = 2; i < N; ++i) {
    sieve[i] = true;
  }
  for (int i = 2; i * i <= N; ++i) {
    if (sieve[i]) {
      for (int j = i * i; j < N; j += i) {
        sieve[j] = false;
      }
    }
  }
  for (int i = 2; i < N; ++i) {
    sieve_sum[i] += sieve_sum[i - 1];
    if (sieve[i]) {
      ++sieve_sum[i];
    }
  }
}

inline void build_palind() {
  for (int i = 1; i < N; ++i) {
    palind_sum[i] += palind_sum[i - 1];
    if (is_palindrome(i)) {
      ++palind_sum[i];
    }
  }
}

int main() {
  int p, q;
  scanf("%d%d", &p, &q);
  build_sieve();
  build_palind();
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if ((long long) sieve_sum[i] * q <= (long long) palind_sum[i] * p) {
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
