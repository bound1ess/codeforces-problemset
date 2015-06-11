#include <cstdio>
#include <algorithm>

#define BEAR "Bear\n"
#define ELEPHANT "Elephant\n"
#define ALIEN "Alien\n"

using namespace std;

const int N = 6;
int a[N];

int inline count(int val, int i)
{
    int count = 0;

    for (; i < N; i++) {
        if (a[i] == val) {
            count++;
        }
    }

    return count;
}

int main()
{
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + N);

    bool four_sticks = false;
    int a_len = 0, b_len = 0;

    for (int i = 0; i < N; i++) {
        if (count(a[i], i) >= 4) {
            four_sticks = true;
            i += 3;
        } else if (a_len > 0) {
            b_len = a[i];
        } else {
            a_len = a[i];
        }
    }

    //printf("head and tail: %d and %d (or vice versa)\n", a_len, b_len);

    if ( ! four_sticks) {
        printf(ALIEN);
    } else {
        printf(a_len == b_len ? ELEPHANT : BEAR);
    }

    return 0;
}
