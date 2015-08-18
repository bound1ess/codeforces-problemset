#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int i = s.length() - 1;

  while (s[i] == 'z' && i > 0) {
    s[i] = 'a';
    --i;
  }

  ++s[i];

  if (t > s) {
    cout << s << endl;
  } else {
    cout << "No such string" << endl;
  }

  return 0;
}
