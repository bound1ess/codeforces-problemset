#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int a[100];

int main()
{
    int n, k;
    scanf("%u %u", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%u", &a[i]);

    sort(a, a + n, greater<int>());

    printf("%u\n", a[k - 1]);

    return 0;
}
