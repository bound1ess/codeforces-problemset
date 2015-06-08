#include <cstdio>

int a[20], ans[3];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ans[i % 3] += a[i];
    }

    //printf("%d %d %d\n", ans[0], ans[1], ans[2]);

    if (ans[0] > ans[1] && ans[0] > ans[2]) {
        printf("chest\n");
        return 0;
    }

    if (ans[1] > ans[0] && ans[1] > ans[2]) {
        printf("biceps\n");
    } else {
        printf("back\n");
    }

    return 0;
}
