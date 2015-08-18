#include <iostream>
#include <string>

using namespace std;

const int N = 26, M = 52;
int sc[M], tc[M];

inline int get(char c) {
  return c >= 'a' ? c - 'a' + N : c - 'A';
}

inline int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  string s, t;
  int a = 0, b = 0;
  cin >> s >> t;

  for (int i = 0, n = s.length(); i < n; ++i) {
    ++sc[get(s[i])];
  }

  for (int i = 0, n = t.length(); i < n; ++i) {
    ++tc[get(t[i])];
  }

  for (int i = 0; i < M; ++i) {
    int val = min(sc[i], tc[i]);

    if (val > 0) {
      sc[i] -= val, tc[i] -= val, a += val;
    }
  }

  for (int i = 0; i < N; ++i) {
    int val = min(sc[i], tc[i + N]);

    if (val > 0) {
      sc[i] -= val, tc[i + N] -= val, b += val;
    }
  }

  for (int i = N; i < M; ++i) {
    int val = min(sc[i], tc[i - N]);

    if (val > 0) {
      sc[i] -= val, tc[i - N] -= val, b += val;
    }
  }

  cout << a << " " << b << endl;
  return 0;
}
