#include <iostream>
#include <map>
#include <vector>

using ll = long long;

using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> prefix(n + 1);
    for (ll i = 1; i <= n; i++) {
        char c;
        cin >> c;
        prefix[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
        prefix[i] += prefix[i - 1];
    }

    map<ll, ll> sum_dist;
    for (ll i = 0; i <= n; i++) {
        sum_dist[prefix[i] - i]++;
    }

    ll cnt = 0;
    for (const auto &[_, v] : sum_dist) {
        if (v >= 2)
            cnt += v * (v - 1) / 2;
    }

    cout << cnt << "\n";
}

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
        solve();
}
