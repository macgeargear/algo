#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n;

float solve(vec<vec<int>> &missions, vec<bool> &used) {
    float ans = 0;
    vec<vec<float>> dp(n, vec<float>(n + 1, 1));

    for (int i = 0; i < n; i++)
        dp[0][i] = missions[0][i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k != j)
                    dp[i][k] = max(dp[i][j], dp[i - 1][j] * missions[i][j]);
            }
        }
    }

    return dp[n - 1][n];
}

int main() {
    cin >> n;
    vec<vec<float>> dp(n + 1, vec<float>(n + 1));
    vec<vec<float>> missions(n, vec<float>(n));
    vec<bool> used(false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> missions[i][j];
}
