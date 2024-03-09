#include <iostream>
#include <vector>

using namespace std;

int n, m;

int max(int a, int b, int c) {
    return max((max(a, b)), c);
}

int solve(vector<vector<int>> &grid) {
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];

    if (n == 1)
        return dp[0][m - 1];
    if (m == 1)
        return dp[n - 1][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j],
                           dp[i - 1][j - 1] + 2 * grid[i][j]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n - 1][m - 1];
}

int main() {
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << solve(grid) << "\n";
}

/*
1 1 10
1 7 10
1 10 20

1 2 3
2
3
*/
