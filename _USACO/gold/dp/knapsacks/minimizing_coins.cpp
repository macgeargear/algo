#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n), dp(x + 1);
    for (auto &c : coins)
        cin >> c;

    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = 2e9;
        for (auto c : coins) {
            if (i - c >= 0)
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    cout << (dp[x] == 2e9 ? -1 : dp[x]);
}
