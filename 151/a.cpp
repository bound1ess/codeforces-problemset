#include <cstdio>

int main() {
  int n, k, l, c, d, p, nl, np;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  int ans = 0, tnl = k * l, tnp = p, tl = c * d;

  while (tnl >= nl && tl > 0 && tnp >= np) {
    tnl -= nl, tnp -= np, --tl, ++ans;
  }

  while (ans % n != 0) {
    --ans;
  }

  printf("%d\n", ans / n);
  return 0;
}
