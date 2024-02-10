#include <iostream>
#include <vector>

using namespace std;

int min_path_sum(vector<vector<int>> grid) {
    int min_sum = 0;
    int n = grid.size(), m = grid[0].size();
    int dp[n][m];
    dp[0][0] = grid[0][0];
    if (n == 1 && m == 1)
        return dp[0][0];

    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[0].size(); j++) {
            dp[i][j] =
                min(grid[i][j] + dp[i][j - 1], grid[i][j] + dp[i - 1][j]);
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << min_path_sum(v);
}
