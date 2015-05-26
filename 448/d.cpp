#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;

    long long l = 1, r = (n * m) + 1;

    while (l < r) {
        long long mid = (l + r) / 2, sum = 0;

        for (long long i = 1; i <= n; i++)
            sum += min(m, (mid - 1) / i);

        if (sum < k)
            l = mid + 1;
        else
            r = mid;
    }

    cout << (l - 1) << endl;

    return 0;
}
