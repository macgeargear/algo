#include <iostream>
#include <vector>

using namespace std;

int n, m;
int solve(vector<vector<int>> &dp) {
    int X = dp[n][m];
    return 0;
}

int main() {
    cin >> n >> m;
    vector<int> V(n), W(m);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int &v : V)
        cin >> v;
    for (int &w : W)
        cin >> w;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            cin >> dp[i][j];
}

/*
5 5
3 10 6 3 5
5 5 3 1 1
---
   1 2 3 4 5
  0 0 0 0 0 0
5 0 0 0 0 0 3
5 0 0 0 0 0 10
3 0 0 0 6 6 10
1 0 3 3 6 9 10
1 0 5 8 8 11 14
---
5 4 3
*/
