#include <iostream>
#include <string>

using namespace std;

const int N = 300;
string m[N];

int main() {
  char chr;
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0 && m[i][i] != chr) {
      cout << "NO" << endl;
      return 0;
    }

    chr = m[i][i];
  }

  for (int i = n - 1; i >= 0; --i) {
    if (chr != m[i][n - i - 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  int count = 0;
  chr = m[0][1];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (m[i][j] == chr) {
        ++count;
      }
    }
  }

  cout << ((n * n) - (n + n - 1) - count == 0 ? "YES" : "NO") << endl;
  return 0;
}
