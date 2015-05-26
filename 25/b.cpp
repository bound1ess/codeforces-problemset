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

    //for (int i = 0; i < n; i++)
    //    printf("%c", num[i]);
    //printf("\n");

    int a = 0, b = 0, off = 0;

    while (n % 2 != 0)
        b++, n -= 3;

    a = n / 2;

    for (int i = 0; a > 0 || b > 0; i++) {
        if (i > 0)
            printf("%c", '-');

        int len;

        if (i % 2 < 1)
            if (a > 0)
                a--, len = 2;
            else
                b--, len = 3;
        else
            if (b > 0)
                b--, len = 3;
            else
                a--, len = 2;

        for (int i = off; i < off + len; i++)
            printf("%c", num[i]);

        off += len;
    }

    printf("\n");

    return 0;
}
