#include <vector>
#include <cstdio>

using namespace std;

class Node {
  public:
    vector <int> v;
    Node() {
      v = vector <int> ();
    }
    void add(int idx) {
      v.push_back(idx);
    }
};

vector <Node> trees;

int depth(int idx) {
  int max_depth = 0;
  for (int i = 0, n = int(trees[idx].v.size()); i < n; ++i) {
    int depth_val = depth(trees[idx].v[i]);
    if (max_depth < depth_val) {
      max_depth = depth_val;
    }
  }
  return max_depth + 1;
}

int main() {
  int n, x, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    trees.push_back(Node());
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x != -1) {
      trees[x - 1].add(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    int depth_val = depth(i);
    if (ans < depth_val) {
      ans = depth_val;
    }
  }
  printf("%d\n", ans);
  return 0;
}
