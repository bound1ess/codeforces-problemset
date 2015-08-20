#include <iostream>
#include <string>

using namespace std;

inline bool has_digit(string &pswd) {
  for (int i = 0, n = pswd.length(); i < n; ++i) {
    if (pswd[i] >= '0' && pswd[i] <= '9') {
      return true;
    }
  }

  return false;
}

inline bool has_letter(string &pswd, bool small = false) {
  for (int i = 0, n = pswd.length(); i < n; ++i) {
    if (small) {
      if (pswd[i] >= 'a' && pswd[i] <= 'z') {
        return true;
      }
    } else {
      if (pswd[i] >= 'A' && pswd[i] <= 'Z') {
        return true;
      }
    }
  }

  return false;
}

inline bool check_pswd(string &pswd) {
  return pswd.length() >= 5u && has_letter(pswd) && has_letter(pswd, true) && has_digit(pswd);
}

int main() {
  string pswd; cin >> pswd;
  cout << (check_pswd(pswd) ? "Correct" : "Too weak") << endl;
  return 0;
}
