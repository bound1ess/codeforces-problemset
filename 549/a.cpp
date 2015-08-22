#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 50;
string grid[N];

int main() {
  int n, m, ans = 0;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      string k;
      k += grid[i][j];
      k += grid[i + 1][j];
      k += grid[i][j + 1];
      k += grid[i + 1][j + 1];

      sort(k.begin(), k.end());

      if (k == "acef") {
        ++ans;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
