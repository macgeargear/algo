#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

vector<pii> points;

int pareto(int l, int r, int &min_y) {
    if (l >= r) {
        if (points[l].second > min_y) {
            min_y = points[l].second;
            return 1;
        } else
            return 0;
    }

    int m = (l + r) / 2;
    int p1 = pareto(m + 1, r, min_y);
    int p2 = pareto(l, m, min_y);
    return p1 + p2;
}

int main() {
    int n;
    cin >> n;
    points.resize(n);

    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;
    sort(points.begin(), points.end());
    int min = -2e9;
    cout << pareto(0, n - 1, min);
}
