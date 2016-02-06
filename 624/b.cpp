#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater <int> ());
  int val = a[0];
  long long ans = 0ll;
  for (int i = 0; i < n; ++i) {
    ans += min(a[i], val);
    val = a[i] < val ? a[i] - 1 : val - 1;
    if (val <= 0) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
