#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > map;

    int n;
    cin >> n;

    vector<int> v_sum(n, 0), h_sum(n, 0);

    for (int i = 0; i < n; i++) {
        vector<int> row(n);

        for (int j = 0; j < n; j++) {
            cin >> row[j];
            v_sum[j] += row[j];
            h_sum[i] += row[j];
        }

        map.push_back(row);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v_sum[j] > h_sum[i]) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
