#include <iostream>
#include <string>

int main()
{
    std::string banner, word = "CODEFORCES";
    std::cin >> banner;

    int banner_length = banner.length(), word_length = word.length();
    int left = 0, right = 0;

    // left => right
    while (banner[left] == word[left]) {
        left++;
    }

    // left <= right
    while (banner[banner_length - 1 - right] == word[word_length - 1 - right]) {
        right++;
    }

    // if left + right >= word, then such substring exists
    std::cout << ((left + right >= word_length) ? "YES\n" : "NO\n");

    return 0;
}
