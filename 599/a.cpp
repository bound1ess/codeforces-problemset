#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int d1, d2, d3;
  scanf("%d%d%d", &d1, &d2, &d3);
  printf("%d\n", min(d1 + d2 + d3, min(min(d1, d2) * 2 + d3 * 2, d1 * 2 + d2 * 2)));
  return 0;
}
