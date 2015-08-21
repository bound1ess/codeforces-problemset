#include <cstdio>

const int N = 100;
int grid[N][N], people[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &grid[i][j]);
    }
  }

  for (int i = 0; i < m; ++i) {
    int best_j = 0;

    for (int j = 1; j < n; ++j) {
      if (grid[i][j] > grid[i][best_j]) {
        best_j = j;
      }
    }

    ++people[best_j];
  }

  int best = 0;

  for (int i = 1; i < n; ++i) {
    if (people[best] < people[i]) {
      best = i;
    }
  }

  printf("%d\n", best + 1);
  return 0;
}
