#include <iostream>
#include <map>
#include <vector>

#define vec vector

using namespace std;

const int M = 998244353;

int n, k;
int main() {
    cin >> n >> k;
    vec<int> dp(k + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        char op;
        int val;
        cin >> op >> val;
        if (op == '+') {
            for (int i = k; i >= val; i--) {
                dp[i] += dp[i - val];
                dp[i] %= M;
            }
        } else {
            for (int i = val; i <= k; i++) {
                dp[i] += (M - dp[i - val]);
                dp[i] %= M;
            }
        }
        cout << dp[k] << "\n";
    }
}
