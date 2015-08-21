#include <iostream>
#include <string>

using namespace std;

int main() {
  string banner, word = "CODEFORCES";
  int left = 0, right = 0, word_len = word.length(), banner_len;
  cin >> banner;
  banner_len = banner.length();

  while (banner[left] == word[left]) {
    ++left;
  }

  while (banner[banner_len - 1 - right] == word[word_len - 1 - right]) {
    ++right;
  }

  cout << (left + right >= word_len ? "YES" : "NO") << endl; 
  return 0;
}
