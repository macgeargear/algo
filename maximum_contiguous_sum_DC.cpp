
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int max(int a, int b, int c) {
    return max(max(a,b), c);
}

int max_crossing_sum(vector<int> arr, int l, int m, int r) {
    int sum = 0;

    // Left sum
    int left_sum = INT_MIN;
    for (int i=m; i>=l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Right sum
    sum = 0;
    int right_sum = INT_MIN;
    for (int i=m+1; i<=r; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    
    return max(left_sum + right_sum, left_sum, right_sum);
}

int max_subarr_sum(vector<int> &nums, int l, int r) {
    if (l >= r) return nums[l];
    int m = (l+r)/2;
    return max(max_subarr_sum(nums, l, m-1),
               max_subarr_sum(nums, m+1, r),
               max_crossing_sum(nums, l, m, r)
               );
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums) cin >> n;
    cout << max_subarr_sum(nums, 0, n-1); 
}
