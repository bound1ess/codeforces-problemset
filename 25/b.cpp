#include <cstdio>

using namespace std;

char num[100], tmp;

int main()
{
    int n;
    scanf("%u", &n);

    scanf("%c", &tmp);

    for (int i = 0; i < n; i++)
        scanf("%c", &num[i]);

    int i = 0;

    if (n % 2 > 0) {
        printf("%c%c%c", num[0], num[1], num[2]);
        i = 3;
    }

    for (; i < n; i += 2) {
        if (i > 0)
            printf("%c", '-');

        printf("%c%c", num[i], num[i + 1]);
    }

    printf("\n");

    return 0;
}
