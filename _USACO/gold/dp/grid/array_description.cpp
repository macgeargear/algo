#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n);

    // base case dp[1][k] = 1 if (a[0] = 0 OR a[0] = k)
    vec<vec<int>> dp(n + 1, vec<int>(m + 1));

    for (int i = 1; i <= m; i++)
        if (nums[0] == i || nums[0] == 0)
            dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
        }
    }
}
