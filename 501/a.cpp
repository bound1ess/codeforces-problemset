#include <algorithm>
#include <cstdio>

using namespace std;

int inline compute(int p, int t)
{
    return max((3 * p) / 10, p - ((p / 250) * t));
}

int main()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (compute(a, c) == compute(b, d)) {
        printf("Tie\n");
    } else if (compute(a, c) > compute(b, d)) {
        printf("Misha\n");
    } else {
        printf("Vasya\n");
    }

    return 0;
}
