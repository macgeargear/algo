#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<int, int>, int> memo;

int mcm(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return memo[{l, r}] = 0;
        return memo[{l, r}];
    }

    if (memo.find({l, r}) != memo.end())
        return memo[{l, r}];

    memo[{l, r}] = 2e9;
    for (int i = l; i < r; i++) {
        int left = mcm(nums, l, i);
        int right = mcm(nums, i + 1, r);
        int curr = nums[l] * nums[i + 1] * nums[r + 1];
        memo[{l, r}] = min(memo[{l, r}], left + right + curr);
    }

    return memo[{l, r}];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> nums[i];
    cout << mcm(nums, 0, n - 1) << "\n";
}
