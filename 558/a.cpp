#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>

using namespace std;

int main() {
  vector<int> left_trees, right_trees;
  map<int, int> profits;
  int n, tree, profit, max_profit = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &tree, &profit);
    profits[tree] = profit;
    max_profit += profit;

    if (tree < 0) {
      left_trees.push_back(tree);
    } else {
      right_trees.push_back(tree);
    }
  }

  if (left_trees.size() == right_trees.size()) {
    printf("%d\n", max_profit);
    return 0;
  }

  sort(left_trees.begin(), left_trees.end(), greater<int>());
  sort(right_trees.begin(), right_trees.end());

  max_profit = 0;
  int min_trees = min(left_trees.size(), right_trees.size());

  for (int i = 0; i < min_trees; ++i) {
    max_profit += profits[left_trees[i]] + profits[right_trees[i]];
  }

  if (left_trees.size() < right_trees.size()) {
    max_profit += profits[right_trees[min_trees]];
  } else {
    max_profit += profits[left_trees[min_trees]];
  }

  printf("%d\n", max_profit);
  return 0;
}
