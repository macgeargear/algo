#include <iostream>
#include <vector>

#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

int unique_paths(int m, int n) {
    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << unique_paths(m, n);
}
