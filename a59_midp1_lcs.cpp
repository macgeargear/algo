#include <iostream>
#include <string>
#include <vector>

#define vec vector

using namespace std;

int n, m;
string a, b;
string solve(vec<vec<int>> &dp) {
    string res = "";
    int i = n, j = m;
    int curr = dp[i][j];

    while (curr != 0 || i != 0 || j != 0) {
        // cout << dp[i][j] << " i: " << i << " j: " << j << "\n";
        // cout << "res: " << res << "\n";
        if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            res = a[i - 1] + res;
            i--;
            j--;
            if (i == 0 || j == 0)
                break;
        } else if (i >= 0 && j >= 0 && dp[i][j] == dp[i - 1][j] &&
                   dp[i][j] == dp[i][j - 1]) {
            i--;
            j--;
        } else if (i >= 0 && j >= 0 && dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (i >= 0 && j >= 0 && dp[i][j] == dp[i][j - 1]) {
            j--;
        }
        if (i == 0 || j == 0)
            break;
        curr = dp[i][j];
    }
    return res;
}

int main() {
    cin >> n >> m;
    cin >> a;
    cin >> b;
    vec<vec<int>> dp(n + 1, vec<int>(m + 1));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            cin >> dp[i][j];
    cout << solve(dp) << "\n";
}
