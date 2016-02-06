#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, c = 0;
  scanf("%d", &n);
  vector < vector <char> > g;
  for (int i = 0; i < n; ++i) {
    vector <char> row;
    for (int j = 0; j < n; ++j) {
      if (0 == i || g[i - 1][j] != 'C') {
        if (0 == j || row[j - 1] != 'C') {
          row.push_back('C');
          ++c;
          continue;
        }
      }
      row.push_back('.');
    }
    g.push_back(row);
  }
  printf("%d\n", c);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      putchar(g[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
