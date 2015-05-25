#include <cstdio>

using namespace std;

const int N = (int) 10e5;
int a[N], b[N];
bool c[N];

int main()
{
    int n, m;

    scanf("%u %u", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%u", &a[i]);

    for (int i = 0; i < m; i++)
        scanf("%u", &b[i]);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        bool make_new = true;

        for (int j = 0; j < m; j++) {
            //printf("c[%u] = %u;\n", j, c[j]);

            if (c[j])
                continue;

            if (b[j] >= a[i]) {
                c[j] = true;
                make_new = false;
                break;
            }
        }

        if (make_new) {
            //printf("task with difficulty %u\n", a[i]);
            ans++;
        }
    }

    printf("%u\n", ans);

    return 0;
}
