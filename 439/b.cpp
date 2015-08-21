#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;
int arr[N];

int main() {
  int n, x;
  long long answer = 0LL;
  cin >> n >> x;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  for (int i = 0; i < n; ++i) {
    answer += (long long) x * arr[i];

    if (x > 1) {
      --x;
    }
  }

  cout << answer << endl;
  return 0;
}
