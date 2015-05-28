#include <cstdio>
#include <utility>

using namespace std;

const int N = (int) 3e3;
int a[N];

int main()
{
    int n;
    scanf("%u", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%u\n", n);

    for (int i = 0; i < n; i++) {
        int k = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }

        swap(a[i], a[k]);
        printf("%u %u\n", i, k);
    }

    return 0;
}
