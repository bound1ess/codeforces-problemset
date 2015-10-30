#include <cstdio>

const int N = 123;
char s[N];

int main() {
  scanf("%s", s + 2);
  s[0] = s[1] = '0';
  for (int i = 0; 0 < s[i]; ++i) {
    for (int j = i + 1; 0 < s[j]; ++j) {
      for (int k = j + 1; 0 < s[k]; ++k) {
        int num = (100 * (s[i] - '0')) + (10 * (s[j] - '0')) + (s[k] - '0');
        if (num % 8 == 0) {
          printf("YES\n%d\n", num);
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
