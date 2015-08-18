#include <iostream>
#include <string>

using namespace std;

const int N = 10;
string d[N];

int main() {
  string s; cin >> s;

  for (int i = 0; i < N; ++i) {
    cin >> d[i];
  }

  for (int i = 0, n = (int) s.length() / N; i < n; ++i) {
    string sub = s.substr(i * N, N);

    for (int j = 0; j < N; ++j) {
      if (d[j] == sub) {
        cout << j;
        break;
      }
    }
  }

  cout << endl;
  return 0;
}
