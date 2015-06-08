#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<string, string> words;

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        words[a] = b;
    }

    string answer;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if (words[word].length() >= word.length()) {
            answer += word;
        } else {
            answer += words[word];
        }

        if (i + 1 < n) {
            answer += " ";
        }
    }

    cout << answer << endl;

    return 0;
}
