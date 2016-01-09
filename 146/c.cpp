#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 123456;
char s[N], t[N];

int main() {
  scanf("%s%s", s, t);
  int n = int(strlen(s)), inv47 = 0, inv74 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '4' && t[i] == '7') {
      ++inv47;
    }
    if (s[i] == '7' && t[i] == '4') {
      ++inv74;
    }
  }
  printf("%d\n", max(inv47, inv74));
  return 0;
}
