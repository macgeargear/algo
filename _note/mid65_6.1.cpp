#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int main() {
    int n;
    cin >> n;
    vec<vec<int>> dp(n + 1);
    for (int i = 0; i < n; i++)
        dp[i][i] = 2 * (i + 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            dp[j][i + j] = 2e9;
            for (int k = j; k < i + j; k++) {
                int curr = dp[j][k] + dp[k + 1][i + j];
                dp[j][i + j] = min(dp[j][i + j], curr);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
}
