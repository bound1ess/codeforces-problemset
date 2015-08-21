#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int n, m;
  string a, b, answer;
  map<string, string> w;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    w[a] = b;
  }

  for (int i = 0; i < n; ++i) {
    cin >> a;

    if (w[a].length() >= a.length()) {
      answer += a;
    } else {
      answer += w[a];
    }

    if (i + 1 < n) {
      answer += " ";
    }
  }

  cout << answer << endl;
  return 0;
}
