#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int main() {
  int n, m, k, sum = 0, id = -1;
  scanf("%d%d", &n, &m);
  queue< pair<int, int> > q;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &k);
    sum += k;
    q.push(make_pair(i + 1, k));
  }

  while ( ! q.empty()) {
    pair<int, int> kid = q.front();
    id = kid.first;
    q.pop();

    if (kid.second > 0) {
      q.push(make_pair(kid.first, kid.second - m));
    }
  }

  printf("%d\n", id);
  return 0;
}
