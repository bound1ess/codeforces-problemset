#include <cstdio>
#include <stack>

const int N = 100010;
int a[N], b[N];

std::stack<int> unused;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    ++b[a[i]];
  }
  for (int i = n; i >= 1; --i) {
    if (b[i] < 1) {
      unused.push(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > n || b[a[i]] > 1) {
      --b[a[i]];
      //b[unused.top()] = 1;
      a[i] = unused.top();
      unused.pop();
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n - 1]);
  return 0;
}
