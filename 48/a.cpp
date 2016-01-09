#include <iostream>
#include <string>

using namespace std;

inline bool wins(const string &a, const string &b) {
  if (a == "rock" && b == "scissors") {
    return true;
  }
  if (a == "scissors" && b == "paper") {
    return true;
  }
  if (a == "paper" && b == "rock") {
    return true;
  }
  return false;
}

int main() {
  string f, m, s;
  cin >> f >> m >> s;
  if (wins(f, m) && wins(f, s)) {
    cout << "F" << endl;
  } else if (wins(m, f) && wins(m, s)) {
    cout << "M" << endl;
  } else if (wins(s, f) && wins(s, m)) {
    cout << "S" << endl;
  } else {
    cout << "?" << endl;
  }
  return 0;
}
