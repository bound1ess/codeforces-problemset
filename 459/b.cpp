#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1234567;
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  int n, min_val = (1LL << 31) - 1, max_val = 0, min_cnt = 0, max_cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    min_val = min(min_val, a[i]);
    max_val = max(max_val, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == min_val) {
      ++min_cnt;
    }
    if (a[i] == max_val) {
      ++max_cnt;
    }
  }
  cout << (max_val - min_val) << ' ';
  cout << (min_val == max_val ? n * (n - 1LL) / 2 : min_cnt * 1LL * max_cnt) << endl;
  return 0;
}
