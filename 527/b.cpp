#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int N = 1 << 7;
int ch[N][N];

int main() {
  int n, dist = 0;
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      ++dist;
      ch[(int) s[i]][(int) t[i]] = i + 1;
    }
  }
  for (int i = 'a'; i <= 'z'; ++i) {
    for (int j = i; j <= 'z'; ++j) {
      if (ch[i][j] > 0 && ch[j][i] > 0) {
        printf("%d\n", dist - 2);
        printf("%d %d\n", ch[i][j], ch[j][i]);
        return 0;
      }
    }
  }
  for (int i = 'a'; i <= 'z'; ++i) {
    char a = 'a', b = 'a';
    while (a <= 'z' && ch[i][(int) a] == 0) {
      ++a;
    }
    while (b <= 'z' && ch[(int) b][i] == 0) {
      ++b;
    }
    if (a <= 'z' && b <= 'z') {
      printf("%d\n", dist - 1);
      printf("%d %d\n", ch[i][(int) a], ch[(int) b][i]);
      return 0;
    }
  }
  printf("%d\n-1 -1\n", dist);
  return 0;
}
