#include <cstdio>

const int MOD = (int) 1e9 + 7;

inline int pow(int base, int exp) {
  int ans = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      ans = (ans * 1LL * base) % MOD;
    }
    exp /= 2;
    base = (base * 1LL * base) % MOD;
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  int result = pow(3, n * 3) - pow(7, n);
  printf("%d\n", result < 0 ? result + MOD : result);
  return 0;
}
