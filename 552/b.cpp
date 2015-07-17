#include <iostream>
#include <cmath>

using namespace std;

inline int count_digits(int num) {
  int digits = 0;

  while (num > 0) {
    num /= 10;
    ++digits;
  }

  return digits;
}

inline int int_pow(int base, int exp) {
  return (int) round(pow((double) base, (double) exp));
}

int main() {
  int num;
  cin >> num;

  long long answer = 0LL, digits;
  int size = count_digits(num);

  while (size > 0) {
    digits = 1LL + num - int_pow(10, size - 1);
    answer += digits * size;
    num -= digits;
    --size;
  }

  cout << answer << endl;
  return 0;
}
