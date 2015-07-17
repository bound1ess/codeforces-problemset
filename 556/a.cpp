#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  int n;
  string str;
  cin >> n >> str;

  stack<char> chars;

  for (int i = 0; i < n; ++i) {
    if (chars.empty() || chars.top() == str[i]) {
      chars.push(str[i]);
    } else {
      chars.pop();
    }
  }

  cout << chars.size() << endl;
  return 0;
}
