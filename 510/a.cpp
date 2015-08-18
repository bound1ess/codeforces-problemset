#include <cstdio>

int main() {
  int n, m, end;
  scanf("%d%d", &n, &m);
  end = m - 1;

  for (int i = 0; i < n; ++i) {
    bool print = true;

    for (int j = 0; j < m; ++j) {
      if (i % 2 == 0) {
        printf("#");
        continue;
      }

      if (print && j == end) {
        print = false;
        end = end == 0 ? m - 1 : 0;
        printf("#");
      } else {
        printf(".");
      }
    }

    printf("\n");
  }

  return 0;
}
