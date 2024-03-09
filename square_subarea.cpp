#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int r, c;

int mn(int a, int b, int c) {
    return min(min(a, b), c);
}

int solve(vec<vec<int>> &grid) {
    vec<vec<int>> dp(r, vec<int>(c));

    for (int i = 0; i < c; i++)
        dp[0][i] = grid[0][i];
    for (int i = 0; i < r; i++)
        dp[i][0] = grid[i][0];

    int ans = 0;
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (grid[i][j]) {
                dp[i][j] = mn(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    return ans;
}

int main() {
    cin >> r >> c;
    vec<vec<int>> grid(r, vec<int>(c));
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    cout << solve(grid) << "\n";
}
