#include <cstdio>
#include <cmath>

int main()
{
    int n, x, sum = 0, ans = 0;
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        sum += val;
    }

    sum = std::abs(sum);
    ans = (sum / x) + ((sum % x > 0) ? 1 : 0);

    printf("%d\n", ans);

    return 0;
}
