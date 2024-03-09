#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<bool>> memo;
void solve(vector<int> &W, int sum) {
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= W[i]; j--) {
            if (dp[j - W[i]])
                dp[j] = 1;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= sum; i++)
        cnt += dp[i];

    cout << cnt << "\n";
    for (int i = 1; i <= sum; i++)
        if (dp[i])
            cout << i << " ";
    cout << "\n";
}

int main() {
    cin >> n;
    vector<int> W(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> W[i], sum += W[i];
    solve(W, sum);
}

/*
2 4 5
0 1 2 3 4 5 6 7 8 9 10 11
1 0 1 0 1 1 1 1 0 1 0  1
*/
