#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int sum = 0;
    int mx = nums[0], tmp_mx = nums[0];
    int mn = nums[0], tmp_mn = nums[0];

    for (int i = 0; i < n; i++)
        sum += nums[i];

    for (int i = 1; i < n; i++) {
        // max subarr
        tmp_mx = max(tmp_mx + nums[i], nums[i]);
        mx = max(tmp_mx, mx);

        // min subarr
        tmp_mn = min(tmp_mn + nums[i], nums[i]);
        mn = min(tmp_mn, mn);
    }

    return (mn == sum) ? mx : max(sum - mn, mx);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums)
        cin >> n;
    cout << solve(nums);
}
