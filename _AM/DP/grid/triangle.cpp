
#include <iostream>
#include <vector>

using namespace std;

int triangle2(vector<vector<int>> &grid) {
}

int triangle(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[n - 1].size();

    int dp[n][m];
    dp[0][0] = grid[0][0];
    if (n == 1)
        return grid[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (j < grid[i].size())
                dp[i][j] = grid[i][j];
            else
                dp[i][j] = 0;
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] += dp[i - 1][0];
    }

    int idx = 1;
    for (int i = 1; i < m; i++) {
        dp[i][idx] += dp[i - 1][idx - 1];
        idx++;
    }

    for (int i = 2; i < n; i++) {
        for (int j = 1; j < grid[i].size() - 1; j++) {
            dp[i][j] =
                min(dp[i - 1][j] + grid[i][j], dp[i - 1][j - 1] + grid[i][j]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    int ans = 2e9;
    for (int i = 0; i < m; i++)
        ans = min(ans, dp[m - 1][i]);

    return ans;
}

int main() {
    vector<vector<int>> v = {{2}, {8, 6}, {1, 5, 7}};
    cout << triangle(v);
}
