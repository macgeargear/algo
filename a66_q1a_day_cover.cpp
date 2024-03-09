#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define vvi vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>

using namespace std;

vvi v;
int n, m;

int days[1002];
vvi stu(22, vi());

int topdown(int cur, int total) {
    if (total == n)
        return 0;
    if (cur < 0)
        return 2e9;

    int notSelected = topdown(cur - 1, total);

    int pls = 0;
    for (auto d : stu[cur]) {
        if (days[d] == 0)
            pls++;
        days[d]++;
    }

    int selected = topdown(cur - 1, total + pls);
    for (auto d : stu[cur])
        days[d]--;

    return min(notSelected, selected + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            stu[i].push_back(x);
        }
    }

    cout << topdown(m - 1, 0);
}
