#include <iostream>
#include <vector>

using namespace std;

int n, x;

int solve(vector<int> &prices, vector<int> &pages) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= x; w++) {
            if (prices[i - 1] > w)
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = max(dp[i - 1][w],
                               dp[i - 1][w - prices[i - 1]] + pages[i - 1]);
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= x; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][x];
}

int main() {
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << solve(prices, pages) << "\n";
}
