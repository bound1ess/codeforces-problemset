#include <iostream>
#include <string>

using namespace std;

const int N = 26;
int ch[N];

int main() {
  int k, n;
  string s;
  cin >> k >> s;
  n = s.length();
  if (n % k != 0) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    ++ch[s[i] - 'a'];
  }
  for (int i = 0; i < N; ++i) {
    if (ch[i] % k != 0) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int q = 0; q < ch[j] / k; ++q) {
        putchar('a' + j);
      }
    }
  }
  putchar('\n');
  return 0;
}
