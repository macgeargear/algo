#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n)), p(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++) {
        vector<int> tmp(n);
        for (int j = 0; j < n; j++)
            cin >> tmp[j];
        v[i] = tmp;
    }

    int ans = -2e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur = v[i][j];
            int mx = -2e9;
            for (int k = 1; k < n; k++) {
                if (i + k >= n || j + k >= n)
                    break;
                cur = max(cur + v[i + k][j + k], v[i + k][j + k]);
                mx = max(mx, cur);
            }
            ans = max(ans, mx);
        }
    }

    cout << ans << "\n";
}
