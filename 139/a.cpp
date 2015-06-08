#include <cstdio>

int a[7];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 7; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;

    while (n > 0) {
        n -= a[ans % 7];
        ans++;
    }

    //printf("days: %d\n", ans);
    printf("%d\n", (ans % 7 == 0) ? 7 : (ans % 7));
}
