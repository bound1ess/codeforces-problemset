#include <iostream>
#include <string>

using namespace std;

const int N = 200000, M = 26;
char x[N], y[N], p[M];

int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < M; ++i) {
    p[i] = 'a' + i;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < M; ++j) {
      if (p[j] == x[i]) {
        p[j] = y[i];
      } else if (p[j] == y[i]) {
        p[j] = x[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    s[i] = p[s[i] - 'a'];
  }
  cout << s << endl;
  return 0;
}
