#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n, sum = 0;
    scanf("%d", &n);

    vector<pair<int, int> > a;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        int w, h;
        scanf("%d %d", &w, &h);
        //printf("w: %d, h: %d\n", w, h);
        a.push_back(make_pair(w, h));
        b.push_back(h);

        sum += w;
    }

    //for (int i = 0; i < n; i++) printf("w: %d, h: %d\n", a[i].first, a[i].second);
    sort(b.begin(), b.end(), greater<int>());

    //printf("sum: %d\n", sum);
    for (int i = 0; i < n; i++) {
        //printf("max height: %d\n", max(left_max_h, right_max_h));
        //printf("width sum: %d\n", sum - a[i].first);
        printf("%d ", (a[i].second == b[0] ? b[1] : b[0]) * (sum - a[i].first));
    }

    printf("\n");

    return 0;
}
