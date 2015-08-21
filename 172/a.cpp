#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<string> numbers;
  string number;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> number;
    numbers.push_back(number);
  }

  int prefix_length = 0, number_length = numbers[0].length();

  for (int i = 0; i < number_length; ++i) {
    char prefix = numbers[0][i];
    bool remains = true;

    for (int j = 1; j < n; ++j) {
      remains = numbers[j][i] == prefix;

      if ( ! remains) {
        break;
      }
    }

    if (remains) {
      ++prefix_length;
    } else {
      break;
    }
  }

  cout << prefix_length << endl;
  return 0;
}
