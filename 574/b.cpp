#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, a, b, ans = -1;
  scanf("%d%d", &n, &m);
  vector< set<int> > adj(n);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].insert(b), adj[b].insert(a);
  }

  for (int i = 0; i < n; ++i) {
    for (int j: adj[i]) {
      vector<int> tmp(adj[i].size() + adj[j].size());
      auto it = set_intersection(
        adj[i].begin(), adj[i].end(), adj[j].begin(), adj[j].end(), tmp.begin()
      );
      tmp.resize(it - tmp.begin());

      for (int k: tmp) {
        int sum = adj[i].size() + adj[j].size() + adj[k].size() - 6;

        if (ans == -1 || ans > sum) {
          ans = sum;
        }
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
