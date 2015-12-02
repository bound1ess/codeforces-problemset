#include <cstdio>
#include <cstring>

const int N = 200100, M = 26;
char s[N];
int freq[M], odd[M];

int main() {
  scanf("%s", s);
  int n = strlen(s), odd_count = 0, odd_mid;
  for (int i = 0; i < n; ++i) {
    ++freq[s[i] - 'a'];
  }
  for (int i = 0; i < M; ++i) {
    if (freq[i] % 2 == 1) {
      odd[odd_count] = i;
      ++odd_count;
    }
  }
  for (int i = 0, j = odd_count - 1; i <= j; ++i, --j) {
    if (i != j) {
      ++freq[odd[i]], --freq[odd[j]];
      odd_count -= 2;
    } else {
      odd_mid = odd[i];
    }
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < freq[i] / 2; ++j) {
      putchar('a' + i);
    }
  }
  if (odd_count > 0) {
    putchar('a' + odd_mid);
  }
  for (int i = M - 1; i >= 0; --i) {
    for (int j = 0; j < freq[i] / 2; ++j) {
      putchar('a' + i);
    }
  }
  putchar('\n');
  return 0;
}
