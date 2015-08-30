#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100005; // 1e5 + 5

int legs[N];
bool hide[N];

vector< vector<int> > adj;

void dfs(int v, int par = 0) {
  if (adj[v].size() <= 2u) {
    hide[v] = true;

    for (int i: adj[v]) {
      if (i != par) {
        dfs(i, v);
      }
    }
  }
}

int main() {
  int n, a, b;
  scanf("%d", &n);
  adj.resize(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    //--a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1u) {
      dfs(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j: adj[i]) {
      if (hide[j]) {
        legs[i] = min(2, legs[i] + 1);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if ( ! hide[i]) {
      int count = 0;

      for (int j: adj[i]) {
        if ( ! hide[j] && (int) adj[j].size() - legs[j] > 1) {
          ++count;
        }
      }

      if (count > 2) {
        printf("No\n");
        return 0;
      }
    }
  }

  printf("Yes\n");
  return 0;
}
