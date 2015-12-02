#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 123456;
int s[N];

int main() {
  int n, k, ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", s + i);
  }
  for (int i = 0; i < n - k; ++i) {
    ans = max(ans, s[i] + s[(n - k) * 2 - i - 1]);
  }
  printf("%d\n", max(ans, s[n - 1]));
  return 0;
}
