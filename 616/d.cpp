#include <cstdio>

const int N = 1234567;
int a[N], freq[N];

inline void add(int id, int &cnt) {
  ++freq[a[id]];
  if (freq[a[id]] == 1) {
    ++cnt;
  }
}

inline void remove(int id, int &cnt) {
  --freq[a[id]];
  if (freq[a[id]] == 0) {
    --cnt;
  }
}

int main() {
  int n, k, pos = 0, cnt = 0, l = -1, r = -1;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    while (pos < n) {
      add(pos, cnt);
      if (k < cnt) {
        remove(pos, cnt);
        break;
      }
      ++pos;
    }
    if (r - l < pos - i) {
      l = i;
      r = pos;
    }
    remove(i, cnt);
  }
  printf("%d %d\n", l + 1, r);
  return 0;
}
