#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int max_h = 0, total = 0;
    int curr_h = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            curr_h++;
        } else {
            //printf("added %d\n", a[i - 1]);
            max_h = max(curr_h, max_h);
            total++;
            curr_h = 1;
        }
    }

    if (curr_h > 0) {
        max_h = max(curr_h, max_h);
        total++;
    }

    printf("%d %d\n", max_h, total);

    return 0;
}
