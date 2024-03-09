#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll M = 1e9 + 7;

int solve(int n, vector<vector<char>> &grid) {
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][0] = grid[i][0] == '.';
        dp[0][i] = grid[0][i] == '.';
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == '.') {
                if (grid[i - 1][j] != '*')
                    dp[i][j] += dp[i - 1][j];
                if (grid[i][j - 1] != '*')
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << solve(n, grid) / M << "\n";
}

/*
. . . .
. * . .
. . . *
* . . .

1 1 1 1
1 0 1 2
1 1 2 0
0 1 3 3

*/
