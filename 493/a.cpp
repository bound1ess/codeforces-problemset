#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
  string home, away;
  int n, t, m;
  char team, card;
  vector< tuple<bool, int, int> > ans;
  map<int, int> h, a;
  cin >> home >> away >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t >> team >> m >> card;
    if (card == 'r') {
      if (team == 'h') {
        if (h[m] < 2) {
          ans.push_back(make_tuple(true, m, t));
          h[m] = 2;
        }
      } else {
        if (a[m] < 2) {
          ans.push_back(make_tuple(false, m, t));
          a[m] = 2;
        }
      }
    } else {
      if (team == 'h') {
        ++h[m];
        if (h[m] == 2) {
          ans.push_back(make_tuple(true, m, t));
        }
      } else {
        ++a[m];
        if (a[m] == 2) {
          ans.push_back(make_tuple(false, m, t));
        }
      }
    }
  }
  for (tuple<bool, int, int> &node: ans) {
    cout << (get<0>(node) ? home : away) << " " << get<1>(node) << " " << get<2>(node);
    cout << endl;
  }
  return 0;
}
