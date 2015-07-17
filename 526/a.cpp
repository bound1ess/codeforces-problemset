#include <cstdio>

const int N = 100;
int pt[N];
char lvl[N];

int main() {
  int n, pts = 0;
  scanf("%d %s", &n, lvl);

  for (int i = 0; i < n; ++i) {
    if (lvl[i] == '*') {
      pt[pts] = i;
      ++pts;
    }
  }

  for (int i = 0; i < pts - 4; ++i) {
    int jump = pt[i + 1] - pt[i];

    while (pt[i] + (jump * 4) < n) {
      bool good = true;

      for (int j = 1; j <= 4; ++j) {
        if (lvl[pt[i] + (j * jump)] != '*') {
          good = false;
          break;
        }
      }

      if (good) {
        printf("yes\n");
        return 0;
      }

      ++jump;
    }
  }

  printf("no\n");
  return 0;
}
