#include <cstdio>
#include <cmath>

inline double find_dist(int a, int b, int c, int d) {
  return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

int main() {
  double dist = 0.;
  int n, k, a = -1e9, b, c, d;
  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &c, &d);

    if (a != -1e9) {
      dist += find_dist(a, b, c, d);
    }

    a = c, b = d;
  }

  printf("%.9f\n", dist * k / 50.);
  return 0;
}
