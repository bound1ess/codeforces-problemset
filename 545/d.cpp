#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100000;
int arr[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  sort(arr, arr + n);
  int ans = 0;
  long long sum = 0LL;

  for (int i = 0; i < n; ++i) {
    if (sum <= arr[i]) {
      ++ans;
      sum += (long long) arr[i];
    }
  }

  printf("%d\n", ans);
  return 0;
}
