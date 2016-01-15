#include <cstdio>
#include <vector>

using namespace std;

inline void dump(const vector<int> &v) {
  printf("%d", int(v.size()));
  for (int i = 0, n = int(v.size()); i < n; ++i) {
    printf(" %d", v[i]);
  }
  putchar('\n');
}

int main() {
  int n, x;
  scanf("%d", &n);
  vector<int> neg, zero, pos;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    (x < 0 ? neg : (x == 0 ? zero : pos)).push_back(x);
  }
  if (int(neg.size()) % 2 == 0) {
    zero.push_back(neg[0]);
    neg.erase(neg.begin());
  }
  if (pos.empty()) {
    pos.push_back(neg[0]), pos.push_back(neg[1]);
    neg.erase(neg.begin()), neg.erase(neg.begin());
  }
  dump(neg), dump(pos), dump(zero);
  return 0;
}
