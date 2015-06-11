#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

char letters[4] = {'A', 'B', 'C', 'D'};

pair<int, char> lengths[4];

bool compare_pairs(const pair<int, char>& one, const pair<int, char>& two)
{
    return one.first < two.first;
}

int main()
{
    for (int i = 0; i < 4; i++) {
        string choice;
        cin >> choice;
        lengths[i] = make_pair(choice.length() - 2, letters[i]);
    }

    sort(lengths, lengths + 4, compare_pairs);

    bool first = false, last = false;

    if (lengths[0].first * 2 <= lengths[1].first) {
        first = true;
    }

    if (lengths[3].first / 2 >= lengths[2].first) {
        last = true;
    }

    //printf(first ? "first is true\n" : "first is false\n");
    //printf(last ? "last is true\n" : "last is false\n");

    cout << (first != last ? (first ? lengths[0].second : lengths[3].second) : letters[2]);
    cout << endl;

    return 0;
}
