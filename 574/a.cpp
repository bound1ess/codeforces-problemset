#include <cstdio>
#include <queue>

int main() {
  int n, x, first, ans = 0;
  std::priority_queue<int> q;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);

    if (i > 0) {
      q.push(x);
    } else {
      first = x;
    }
  }

  while (q.top() >= first) {
    int max = q.top();
    q.pop();
    q.push(max - 1);
    ++first, ++ans;
  }

  printf("%d\n", ans);
  return 0;
}
