#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> dp(1e6 + 1);
const int M = 1000000007;

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
        dp[i] %= M;
    }

    cout << dp[n];
}
