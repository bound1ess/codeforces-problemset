#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  printf("%d\n", max(0, (int) ceil(y / 100.0 * n) - x));
  return 0;
}
