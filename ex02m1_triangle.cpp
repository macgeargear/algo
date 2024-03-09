#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n][n], dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> v[i][j];
            dp[i][j] = v[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j >= 0; j--) {
            dp[i][j] = v[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < i + 1; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[0][0] << "\n";
}

/*
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

30
23 21
20 13 10
7 12 10 10
4 5 2 6 5
*/
