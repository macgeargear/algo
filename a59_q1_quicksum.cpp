#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> v(n, vector<int>(m)), p(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            p[i][j] =
                v[i - 1][j - 1] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++)
    //         cout << p[i][j] << " ";
    //     cout << "\n";
    // }
    // return 0;
    while (k--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << p[r2 + 1][c2 + 1] - p[r2 + 1][c1] - p[r1][c2 + 1] + p[r1][c1]
             << "\n";
    }
}
