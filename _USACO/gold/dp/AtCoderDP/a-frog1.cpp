#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
        return 0;
    if (n == 2)
        return abs(nums[0] - nums[1]);
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(nums[0] - nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(nums[i] - nums[i - 1]),
                    dp[i - 2] + abs(nums[i] - nums[i - 2]));
    }
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n + 1);
    for (int &x : v)
        cin >> x;
    cout << solve(v);
}
