#include <cstdio>
#include <algorithm>

using std::swap;

const int N = (int) 1e5;
int arr[N];

void quicksort(int l, int r);

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  quicksort(0, n - 1);
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

void quicksort(int l, int r) {
  int i = l, j = r;
  int pivot = arr[(l + r) >> 1];

  while (i <= j) {
    while (arr[i] < pivot) {
      ++i;
    }

    while (arr[j] > pivot) {
      --j;
    }

    if (i <= j) {
      swap(arr[i], arr[j]);
      ++i, --j;
    }
  }

  if (l < j) {
    quicksort(l, j);
  }

  if (i < r) {
    quicksort(i, r);
  }
}
