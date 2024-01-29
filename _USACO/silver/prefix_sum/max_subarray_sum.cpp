#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> prefix(n+1);
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        prefix[i] = prefix[i-1] + x;
    }

    ll min_pf = prefix[0];
    ll ans = prefix[1];

    for (int i=1; i<=n; i++) {
        ans = max(ans, prefix[i] - min_pf);
        min_pf = min(min_pf, prefix[i]);
    }

    cout << ans;
}
