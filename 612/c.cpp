#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

const int N = 1234567, M = 4;
char s[N];
const char O[M] = {'(', '[', '<', '{'}, C[M] = {')', ']', '>', '}'};

int main() {
  scanf("%s", s);
  int n = int(strlen(s)), ans = 0;
  stack<char> st;
  for (int i = 0; i < n; ++i) {
    bool opening = false;
    for (int j = 0; j < M; ++j) {
      if (O[j] == s[i]) {
        opening = true;
        break;
      }
    }
    if (opening) {
      st.push(s[i]);
      continue;
    }
    if (st.empty()) {
      puts("Impossible");
      return 0;
    }
    int open_idx, close_idx;
    for (int j = 0; j < M; ++j) {
      if (O[j] == st.top()) {
        open_idx = j;
        break;
      }
    }
    for (int j = 0; j < M; ++j) {
      if (C[j] == s[i]) {
        close_idx = j;
        break;
      }
    }
    if (open_idx != close_idx) {
      ++ans;
    }
    st.pop();
  }
  if (st.empty()) {
    printf("%d\n", ans);
  } else {
    puts("Impossible");
  }
  return 0;
}
