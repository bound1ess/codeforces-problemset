#include <cstdio>
#include <deque>

using namespace std;

int fac(int n) {
  return n < 2 ? 1 : n * fac(n - 1);
}

int main() {
  int n, k, card;
  deque<int> a, b;

  scanf("%d %d", &n, &k);

  for (int i = 0; i < k; ++i) {
    scanf("%d", &card);
    a.push_back(card);
  }

  scanf("%d", &k);

  for (int i = 0; i < k; ++i) {
    scanf("%d", &card);
    b.push_back(card);
  }

  int states = 0, max_states = fac(n + 1);

  while (states <= max_states && ! a.empty() && ! b.empty()) {
    ++states;

    int card_a = a.front(), card_b = b.front();
    a.pop_front();
    b.pop_front();

    if (card_a < card_b) {
      b.push_back(card_a);
      b.push_back(card_b);
    } else {
      a.push_back(card_b);
      a.push_back(card_a);
    }
  }

  if (states > max_states) {
    printf("-1\n");
  } else {
    printf("%d %d\n", states, a.empty() ? 2 : 1);
  }

  return 0;
}
