#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ipair;

int main()
{
    int n, m;
    cin >> n >> m;

    queue<ipair> q;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        sum += tmp;

        q.push(make_pair(i + 1, tmp));
    }

    int id = -1;

    while ( ! q.empty()) {
        ipair kid = q.front();
        q.pop();
        //cout << kid.second << endl;

        if (kid.second > 0) {
            q.push(make_pair(kid.first, kid.second - m));
        }

        id = kid.first;
    }

    cout << id << endl;

    return 0;
}
