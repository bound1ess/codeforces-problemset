#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector <int> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(1);
    int m;
    while ((m = int(v.size())) >= 2 && v[m - 1] == v[m - 2]) {
      ++v[m - 2];
      v.erase(v.end() - 1);
    }
  }
  for (int i = 0, m = int(v.size()); i < m; ++i) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", v[i]);
  }
  putchar('\n');
  return 0;
}
