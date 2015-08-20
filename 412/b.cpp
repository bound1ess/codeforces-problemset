#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

const int N = 100;
int a[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }

  sort(a, a + n, greater<int>());

  printf("%d\n", a[k - 1]);
  return 0;
}
