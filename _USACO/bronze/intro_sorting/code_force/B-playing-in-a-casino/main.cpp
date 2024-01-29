#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> players(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> players[i][j];
            }
        }
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            ll sum = 0;
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                temp[j] = players[j][i];
            }
            sort(all(temp));
            for (int i = 0; i < n; i++) {
                ans += llabs(i * (temp[i]) - sum);
                sum += temp[i];
            }
        }
        cout << ans << "\n";
    }
}