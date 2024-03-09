#include <iostream>
#include <string>

using namespace std;

int solve(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    return dp[n][m];
}

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    cout << solve(a, b);
}
