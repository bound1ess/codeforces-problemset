#include <cstdio>
#include <map>

using std::map;

class Number {
  public:
    int first;
    int last;
    int total;

    Number(int first): first(first), last(first), total(1) {}

    void update(int last) {
      this->last = last;
      ++total;
    }
};

int main() {
  int n;
  scanf("%d", &n);

  map<int, Number*> nums;
  int max = 1;

  for (int i = 0; i < n; ++i) {
    int num;
    scanf("%d", &num);

    if (nums.find(num) == nums.end()) {
      nums[num] = new Number(i);
    } else {
      nums[num]->update(i);

      if (nums[num]->total > max) {
        max = nums[num]->total;
      }
    }
  }

  int min_size = 1 << 30;
  int first = 0, last = n - 1;

  for (auto it = nums.begin(); it != nums.end(); ++it) {
    if (it->second->total != max) {
      continue;
    }

    int size = it->second->last - it->second->first + 1;

    if (size < min_size) {
      min_size = size;
      first = it->second->first;
      last = it->second->last;
    }
  }

  printf("%d %d\n", first + 1, last + 1);
  return 0;
}
