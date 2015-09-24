#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > adj;
vector<int> cats;

void dfs(int v, int m, int &ans, int current, int parent) {
  if (current > m) {
    return;
  }
  if (v != 0 && adj[v].size() == 1u && adj[v][0] == parent) {
    ++ans;
    return;
  }
  for (int adj_v: adj[v]) {
    if (adj_v != parent) {
      dfs(adj_v, m, ans, cats[adj_v] ? current + 1 : 0, v);
    }
  }
}

int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  adj.resize(n);
  cats.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &cats[i]);
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, m, ans, cats[0], -1);
  printf("%d\n", ans);
  return 0;
}
