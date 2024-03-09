#include <algorithm>
#include <iostream>
#include <vector>

#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int p, k, A, B;
vector<int> avg;

ll num_avg(int l, int r) {
    return upper_bound(all(avg), r) - lower_bound(all(avg), l);
}

ll solve(ll l, ll r) {
    ll num = num_avg(l, r);
    if (num == 0)
        return A;
    ll cur = (r - l + 1) * num * B;
    if (l == r)
        return cur;
    ll m = (r + l) / 2;
    return min(cur, solve(l, m) + solve(m + 1, r));
}

int main() {
    cin >> p >> k >> A >> B;
    int n = 1 << p;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        avg.push_back(x - 1);
    }
    sort(avg.begin(), avg.end());
    cout << solve(0, n - 1);
}
