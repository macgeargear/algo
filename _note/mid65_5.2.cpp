#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        dp[i][0] = nums[i];

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < i; j++) {
        }
    }
}
