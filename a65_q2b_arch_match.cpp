#include <cstring>
#include <iostream>

using namespace std;

const int N = 505;
int n;
int dp[N][N];
bool memo[N][N];
int arr[N];

int solve(int l, int r) {
    if (l >= r)
        return 0;
    if (memo[l][r])
        return dp[l][r];
    memo[l][r] = true;
    dp[l][r] = solve(l + 1, r - 1) + arr[l] * arr[r];
    for (int k = l; k < r; k++) {
        dp[l][r] = max(dp[l][r], solve(l, k) + solve(k + 1, r));
    }
    return dp[l][r];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    memset(memo, false, sizeof(memo));
    memset(dp, 0, sizeof(memo));
    cout << solve(1, n);
}
