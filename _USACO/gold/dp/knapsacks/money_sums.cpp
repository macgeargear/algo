#include <iostream>
#include <vector>

using namespace std;

int n;
void solve(vector<int> &coins, int sum) {
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++) {
        for (int &c : coins) {
            if (i - c >= 0)
                dp[i] = max(dp[i], dp[i - c]);
        }
    }
    int cnt = 0;
    for (int &x : dp)
        cnt += x;
    cout << cnt << "\n";
    for (int i = 1; i <= sum; i++) {
        if (dp[i])
            cout << i << " ";
    }
}

int main() {
    cin >> n;
    vector<int> coins(n);
    int sum = 0;
    for (int &c : coins) {
        cin >> c;
        sum += c;
    }
    solve(coins, sum);
}

/*
0 1 2 3 4 5 6 7 8 9 10 11 12 13
*/
