#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline int parse(const string &s) {
  int ans = 0;

  for (int i = 0, n = s.length(); i < n; ++i) {
    ans = ans * 10 + (s[i] - '0');
  }

  return ans;
}

int main() {
  string s;
  vector<string> ans;
  cin >> s;

  while (parse(s) > 0) {
    string t;

    for (int i = 0, n = s.length(); i < n; ++i) {
      if (s[i] > '0') {
        t += '1';
        --s[i];
      } else if ( ! t.empty()) {
        t += '0';
      }
    }

    ans.push_back(t);
  }

  cout << ans.size() << endl;

  if (ans.size() > 0u) {
    for (int i = 0, n = ans.size(); i < n - 1; ++i) {
      cout << ans[i] << " ";
    }

    cout << ans[ans.size() - 1u] << endl;
  }

  return 0;
}
