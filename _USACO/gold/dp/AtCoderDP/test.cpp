#include <iostream>
#include <vector>

using namespace std;

int n, m;
int solve(vector<int> &nums, int m) {
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = m; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    return dp[m];
}

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;
    cout << solve(nums, m) << "\n";
}
