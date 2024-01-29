#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> cows(n);
    ll max_tution = 0;
    ll money = 2e9;

    for (ll& cow : cows)
        cin >> cow;
    sort(all(cows));

    for (int i=0; i<n; i++) {
        ll tution = (n-i)*cows[i];
        if (tution > max_tution) {
            money = cows[i];
            max_tution = tution;
        }
    }
    cout << max_tution << " " << money; 
}
