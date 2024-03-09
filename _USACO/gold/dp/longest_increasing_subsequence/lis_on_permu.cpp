#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n;

int solve(vec<int> &A, vec<int> &B) {
    vec<vec<int>> dp(n + 1, vec<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int main() {
    cin >> n;
    vec<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << solve(A, B) << "\n";
}
