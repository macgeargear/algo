#include <iostream>
#include <string>

#define vec vector

using namespace std;

string a, b;

int solve(string a, string b) {
    int n = a.size();
    int m = b.size();
    vec<vec<int>> dp(n + 1, vec<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int main() {
    cin >> a >> b;
    cout << solve(a, b);
}
