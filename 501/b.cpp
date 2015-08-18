#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

int main() {
  int n;
  map<string, string> m;
  string a, b;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    bool found = false;
    cin >> a >> b;

    for (pair<string, string> user: m) {
      if (user.second == a) {
        //user.second = b;
        m[user.first] = b;
        found = true;
        break;
      }
    }

    if ( ! found) {
      m[a] = b;
    }
  }

  cout << m.size() << endl;

  for (pair<string, string> user: m) {
    cout << user.first << " " << user.second << endl;
  }
}
