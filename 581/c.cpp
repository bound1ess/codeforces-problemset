#include <cstdio>
#include <queue>

using namespace std;

const int N = 10, LIMIT = 100;
queue<int> q[N];

inline void add(int x) {
  int up = (x / 10 + 1) * 10;
  q[up - x - 1].push(x);
}

int main() {
  int n, k, x, sum = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    sum += x / N;
    if (x < LIMIT) {
      add(x);
    }
  }
  while (k > 0) {
    bool stop = true;
    for (int i = 0; i < N; ++i) {
      if (q[i].size() > 0u) {
        if (i + 1 > k) {
          break;
        }
        int val = q[i].front() + i + 1;
        q[i].pop();
        ++sum, k -= i + 1;
        stop = false;
        if (val < LIMIT) {
          add(val);
        }
        break;
      }
    }
    if (stop) {
      break;
    }
  }
  printf("%d\n", sum);
  return 0;
}
