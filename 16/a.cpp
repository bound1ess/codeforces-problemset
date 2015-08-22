#include <iostream>
#include <string>

using namespace std;

inline bool is_row_correct(string &row) {
  char chr = row[0];

  for (int i = 1, n = row.length(); i < n; ++i) {
    if (chr != row[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, m;
  bool ans = true;
  string row;
  char prev;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> row;

    if ( ! ans) {
      continue;
    }

    ans = is_row_correct(row);

    if (ans) {
      if (i > 0) {
        ans = prev != row[0];
      }

      if (ans) {
        prev = row[0];
      }
    }
  }

  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
