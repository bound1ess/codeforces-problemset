#include <cstdio>
#include <algorithm>

using namespace std;

int a[100];

int main()
{
    int n;
    scanf("%u", &n);

    for (int i = 0; i < n; i++) {
        scanf("%u", &a[i]);
    }

    int min_val = (int) 1e6;

    for (int i = 0; i < n; i++) {
        int tmp = 0;

        for (int j = 0; j < a[i]; j++) {
            int tmp2;
            scanf("%u", &tmp2);

            tmp += tmp2;
        }

        min_val = min(min_val, (tmp * 5) + (15 * a[i]));
    }

    printf("%u\n", min_val);

    return 0;
}
