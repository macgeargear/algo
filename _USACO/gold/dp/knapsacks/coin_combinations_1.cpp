#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int M = 1e9 + 7;

// dp[w] = sum(i=1->n)(dp[w-coins[i]])
int main() {
    int n, x;
    cin >> n >> x;

    vector<ll> coins(n), dp(x + 1);
    dp[0] = 1;

    for (auto& c : coins)
        cin >> c;

    for (int i = 1; i <= x; i++) {
        for (auto& c : coins) {
            if (i - c >= 0)
                dp[i] += dp[i - c];
        }
        dp[i] %= M;
    }

    cout << dp[x];
}
