#include <iostream>

using namespace std;

int gcd(int a, int b) {
  return 0 < b ? gcd(b, a % b) : a;
}

inline int solve(int x, int y, int z) {
  return z / ((long long) x * y / gcd(x, y));
}

int main() {
  int x, y, a, b;
  scanf("%d%d%d%d", &x, &y, &a, &b);
  printf("%d\n", solve(x, y, b) - solve(x, y, a - 1));
  return 0;
}
