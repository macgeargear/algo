#include <iostream>
#include <vector>

using namespace std;

int n;

int solve(vector<vector<int>> &act) {
    vector<vector<int>> dp(n, vector<int>(3));
    int ans = 0;

    for (int i = 0; i < 3; i++)
        dp[0][i] = act[0][i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int cur_max = 0;
            for (int k = 0; k < 3; k++) {
                if (j != k)
                    cur_max = max(cur_max, dp[i - 1][k]);
            }
            dp[i][j] = cur_max + act[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 3; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    for (int i = 0; i < 3; i++)
        ans = max(ans, dp[n - 1][i]);

    return ans;
}

int main() {
    cin >> n;
    vector<vector<int>> act(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> act[i][j];
    }
    cout << solve(act);
}
