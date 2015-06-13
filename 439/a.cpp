#include <cstdio>

using namespace std;

const int PAUSE = 10, JOKE = 5;

int a[100];

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum + (n - 1) * PAUSE > d) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", (d - sum) / JOKE);

    return 0;
}
