#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums, int sum1, int sum2, int idx, int &diff) {
    if (idx == nums.size()) return min(diff, abs(sum1 - sum2));
    int diff1 = solve(nums, sum1 + nums[idx], sum2, idx+1, diff);
    int diff2 = solve(nums, sum1, sum2 + nums[idx], idx+1, diff);
    return min(diff1, diff2);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums) cin >> n;
    int min_diff = 2e9; 
    cout << solve(nums, 0, 0, 0, min_diff);
}
