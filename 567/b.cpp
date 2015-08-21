#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n, ans = 0, curr = 0;
  set<int> all;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int id;
    char act;
    cin >> act >> id;

    if (act == '+') {
      all.insert(id);
      ++curr;
      ans = max(curr, ans);
    } else {
      if (all.find(id) == all.end()) {
        ++ans;
      } else {
        --curr;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
