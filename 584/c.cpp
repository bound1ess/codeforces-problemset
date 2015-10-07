#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int n, t, same = 0;
  string a, b;
  cin >> n >> t >> a >> b;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      ++same;
    }
  }
  if (n - t > (n + same) / 2) {
    puts("-1");
    return 0;
  }
  int x = min(same, n - t), y = max(0, n - same - t), z = y;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (x > 0) {
        putchar(a[i]);
        --x;
      } else {
        putchar(a[i] == 'a' ? 'b' : 'a');
      }
    } else {
      if (y > 0) {
        putchar(a[i]);
        --y;
      } else if (z > 0) {
        putchar(b[i]);
        --z;
      } else {
        if (a[i] != 'a' && b[i] != 'a') {
          putchar('a');
        } else if (a[i] != 'b' && b[i] != 'b') {
          putchar('b');
        } else {
          putchar('c');
        }
      }
    }
  }
  puts("");
  return 0;
}
