#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > numbers;

    for (int i = 0; i < n; i++) {
        string number;
        cin >> number;

        int length = number.length();
        vector<int> digits;

        for (int j = 0; j < length; j++) {
            digits.push_back(number[j] - '0');
        }

        numbers.push_back(digits);
    }

    int prefix_length = 0, number_length = numbers[0].size();

    for (int i = 0; i < number_length; i++) {
        int prefix = numbers[0][i];
        bool remains = true;

        for (int j = 1; j < n; j++) {
            remains = numbers[j][i] == prefix;

            if ( ! remains) {
                break;
            }
        }

        if (remains) {
            prefix_length++;
        } else {
            break;
        }
    }

    cout << prefix_length << endl;

    return 0;
}
