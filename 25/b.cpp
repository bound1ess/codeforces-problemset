#include <iostream>
#include <string>

using namespace std;

const int N = 100;
char num[N];

int main() {
  int n, i = 0;
  string code;
  cin >> n >> code;

  if (n % 2 > 0) {
    i = 3;

    for (int j = 0; j < i; ++j) {
      cout << code[j];
    }
  }

  for (int j = i; j < n; j += 2) {
    if (j > 0) {
      cout << '-';
    }

    cout << code[j] << code[j + 1];
  }

  cout << endl;
  return 0;
}
