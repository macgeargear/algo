#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums, vector<int> &prefix, int k) {
    int n = nums.size();
    if (k > n)
        return 0;

    int max_sum = INT_MIN;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += nums[i];
        if (i >= k)
            curr_sum -= nums[i - k];
        max_sum = max(curr_sum, max_sum);

        for (int j = 1; j < k; j++) {
            if (i - j >= 0) {
                curr_sum -= nums[i - j + 1];
                max_sum = max(max_sum, curr_sum);
                curr_sum += nums[i - j + 1];
            }
        }
    }

    return max_sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n), prefix(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        prefix[i + 1] = prefix[i] + nums[i];
    }
    cout << solve(nums, prefix, k);
}
