#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int fx, fy, sx, sy;
  scanf("%d%d%d%d", &fx, &fy, &sx, &sy);
  printf("%d\n", max(abs(sx - fx), abs(sy - fy)));
  return 0;
}
