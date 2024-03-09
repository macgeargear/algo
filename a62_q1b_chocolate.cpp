#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, k;
const int M = 1e6 + 3;

ll solve(int n, vector<int> &nums) {
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w < k; w++) {
            if (i - nums[w] >= 0) {
                dp[i] += dp[i - nums[w]];
                dp[i] %= M;
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    return dp[n];
}

int main() {
    cin >> n >> k;
    vector<int> nums(k);
    for (int &n : nums)
        cin >> n;
    cout << solve(n, nums);
}
