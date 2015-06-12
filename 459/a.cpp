#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int side;

    if (x1 == x2) {
        side = abs(y1 - y2);
    } else if (y1 == y2) {
        side = abs(x1 - x2);
    } else {
        side = abs(x1 - x2);

        if (side != abs(y1 - y2)) {
            printf("-1\n");
            return 0;
        }
    }

    int x3, y3, x4, y4;

    if (x1 == x2) {
        y3 = y1, y4 = y2;
        x3 = x1 + side, x4 = x2 + side;
    } else if (y1 == y2) {
        x3 = x1, x4 = x2;
        y3 = y1 - side, y4 = y2 - side;
    } else {
        x3 = x1, y3 = y2;
        x4 = x2, y4 = y1;
    }

    printf("%d %d %d %d\n", x3, y3, x4, y4);

    return 0;
}
