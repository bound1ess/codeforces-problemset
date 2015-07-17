#include <iostream>

using namespace std;

const int N = (int) 1e5;
int arr[N];

void quicksort(int l, int r);

int main() {
  int n, x;
  cin >> n >> x;

  long long answer = 0LL;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  quicksort(0, n - 1);

  for (int i = 0; i < n; ++i) {
    answer += (long long) x * arr[i];

    if (x > 1) {
      --x;
    }
  }

  cout << answer << endl;  
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
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      ++i, --j;
    }
  }

  if (i < r) {
    quicksort(i, r);
  }

  if (l < j) {
    quicksort(l, j);
  }
}
