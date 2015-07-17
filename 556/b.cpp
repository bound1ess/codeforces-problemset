#include <cstdio>

inline int rotate(int curr, int total, bool clockwise) {
  if (clockwise) {
    return (curr + 1) % total;
  } else {
    return curr - 1 < 0 ? total - 1 : curr - 1;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  while (arr[0] != 0) {
    for (int i = 0; i < n; ++i) {
      arr[i] = rotate(arr[i], n, i % 2 == 0);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (arr[i] != i) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}
