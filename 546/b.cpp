#include <cstdio>
#include <algorithm>

const int N = 3000;
int arr[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i); 
  }

  std::sort(arr, arr + n);
  int coins = 0;

  for (int i = 1; i < n; ++i) {
    while (arr[i - 1] >= arr[i]) {
      ++arr[i], ++coins;
    }
  }

  printf("%d\n", coins);
  return 0;
}
