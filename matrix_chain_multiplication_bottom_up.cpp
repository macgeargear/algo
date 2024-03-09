#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n;

int main() {
    cin >> n;
    vec<int> nums(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> nums[i];

    vec<vec<int>> dp(n, vec<int>(n));
    // base case
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = nums[i] * nums[i + 1] * nums[i + 2];

    // transition
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            dp[j][i + j] = 2e9;
            for (int k = j; k < i + j; k++) {
                int cost = nums[j] * nums[k + 1] * nums[i + j + 1];
                int curr_cost = dp[j][k] + dp[k + 1][i + j] + cost;
                dp[j][i + j] = min(dp[j][i + j], curr_cost);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "ans\n";
    cout << dp[0][n - 1];
}

/*
5
10 5 1 5 10 2
*/
