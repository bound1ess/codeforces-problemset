#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3;
int x[N], y[N];

int main() {
  int area = 0, side = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", x + i, y + i);
    area += x[i] * y[i];
    if (y[i] > x[i]) {
      swap(y[i], x[i]);
    }
  }
  while (side * side < area) {
    ++side;
  }
  if (side * side != area) {
    puts("-1");
    return 0;
  }
  int id = -1, cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (x[i] == side) {
      ++cnt, id = i;
    }
  }
  if (id == -1 || cnt == 2) {
    puts("-1");
    return 0;
  }
  if (cnt == 3) {
    printf("%d\n", side);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < y[i]; ++j) {
        for (int k = 0; k < side; ++k) {
          printf("%c", i + 'A');
        }
        printf("\n");
      }
    }
    return 0;
  }
  int left = side - y[id], mid = -1;
  vector<char> tmp;
  for (int i = 0; i < N; ++i) {
    if (i != id) {
      if (y[i] == left) {
        swap(x[i], y[i]);
      } else if (x[i] != left) {
        puts("-1");
        return 0;
      }
      if (mid == -1) {
        mid = y[i];
      }
      tmp.push_back(i + 'A');
    }
  }
  printf("%d\n", side);
  for (int i = 0; i < N; ++i) {
    if (i == id) {
      for (int j = 0; j < y[id]; ++j) {
        for (int k = 0; k < side; ++k) {
          printf("%c", id + 'A');
        }
        printf("\n");
      }
    }
  }
  for (int i = 0; i < left; ++i) {
    for (int j = 0; j < side; ++j) {
      printf("%c", tmp[j < mid ? 0 : 1]);
    }
    printf("\n");
  }
  return 0;
}
