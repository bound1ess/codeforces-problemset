#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 4;
const char letters[N] = {'A', 'B', 'C', 'D'};

typedef pair<int, char> opt;
opt lengths[N];

inline bool compare(opt &one, opt &two) {
  return one.first < two.first;
}

int main() {
  string choice;

  for (int i = 0; i < N; ++i) {
    cin >> choice;
    lengths[i] = make_pair(choice.length() - 2u, letters[i]);
  }

  sort(lengths, lengths + N, compare);
  bool first = lengths[0].first * 2 <= lengths[1].first;
  bool last = lengths[3].first / 2 >= lengths[2].first;

  cout << (first != last ? (first ? lengths[0].second : lengths[3].second) : letters[2]);
  cout << endl;
  return 0;
}
