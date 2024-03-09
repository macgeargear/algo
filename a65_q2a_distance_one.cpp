#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e8 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1), ps(n + 1);
    ps[0] = 1;  // 0...0

    for (int i = 1; i <= n; i++) {
        if (i <= k)
            dp[i] = 1;
        else
            dp[i] = ps[i - k];
        ps[i] = (ps[i - 1] + dp[i]) % MOD;
    }

    cout << ps[n] << "\n";
}
