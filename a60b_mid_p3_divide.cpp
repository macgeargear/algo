#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int M = 1997;

int n, k;

int solve(int n, int k) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1)
                dp[i][j] = 1;
            else if (i > j)
                dp[i][j] = 0;
            else
                dp[i][j] = i * dp[i][j - 1] + dp[i - 1][j - 1];
            dp[i][j] %= M;
        }
    }
    // for (int i = 0; i <= k; i++) {
    //     for (int j = 0; j <= n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[k][n];
}

int main() {
    cin >> n >> k;
    cout << solve(n, k) << "\n";
}

/*
_ 0 1 2 3 4 5 6 7
0 0 0 0 0 0 0 0 0
1 0 1 1 1 1 1 1 1
2 0 0 1 3 7 15 31 63
3 0 0 0 1 6 25 90 301
4 0 0 0 0 1
*/
