#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> m0(4);
int n, m;

int solve(int step, ll i, ll j) {
    if (step == 1)
        return m0[2 * i + j];
    ll m = 1LL << (step - 1);
    if (i < m && j < m)
        return solve(step - 1, i, j);
    else if (i >= m && j < m)
        return -solve(step - 1, i - m, j);
    else if (i < m && j >= m)
        return solve(step - 1, j - m, i);
    else
        return -solve(step - 1, j - m, i - m);
}

int main() {
    cin >> n >> m;
    int len = 1 << n;
    for (int i = 0; i < 4; i++)
        cin >> m0[i];
    while (m--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(n, a - 1LL, b - 1LL) << "\n";
    }
}
