#include <cstdio>

using namespace std;

const int N = (int) 1e3;

int inline squared(int x)
{
    return x * x;
}

int main()
{
    int ans = 0, n, m;
    scanf("%u %u", &n, &m);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (squared(i) + j == n && i + squared(j) == m) {
                ans++;
            }
        }
    }

    printf("%u\n", ans);

    return 0;
}
