#include <iostream>
#include <string>

using namespace std;

inline int parse(string &time) {
  return (time[0] - '0') * 10 + (time[1] - '0');
}

inline int subtract(int a, int b, int c) {
  return a - b < 0 ? (c + a - b) : a - b;
}

inline string format(int n) {
  string result;

  if (n > 9) {
    result += '0' + n / 10;
  } else {
    result += '0';
  }

  result += '0' + n % 10;
  return result;
}

int main() {
  string s, t;
  int left, right;
  cin >> s >> t;

  string s_left = s.substr(0, 2), s_right = s.substr(3);
  string t_left = t.substr(0, 2), t_right = t.substr(3);
  left = subtract(parse(s_left), parse(t_left), 24);

  if (parse(s_right) - parse(t_right) < 0) {
    left = subtract(left, 1, 24);
  }

  right = subtract(parse(s_right), parse(t_right), 60);
  cout << format(left) << ":" << format(right) << endl;
  return 0;
}
