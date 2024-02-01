#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

ll solve(vector<int> &nums, int n) {
    vector<int> prefix(n+1);
    for (int i=0; i<n; i++) prefix[i+1] = nums[i] + prefix[i];
    int min_prefix=prefix[0];
    ll ans=INT_MIN;
    for (int i=1; i<=n; i++) {
        ans = max(ans, prefix[i] - 1LL*min_prefix);
        min_prefix = min(min_prefix, prefix[i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums) cin >> n;
    cout << solve(nums, nums.size()); 
}
