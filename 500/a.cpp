#include <cstdio>

int a[30000];

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
    }

    int i;

    for (i = 1; i < t; i += a[i - 1]) {}

    printf(i <= t ? "YES\n" : "NO\n");

    return 0;
}
