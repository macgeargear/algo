#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<ll> weights;

ll recurse_apples(int index, ll sum1, ll sum2) {
    if (index == n)
        return abs(sum1 - sum2);
    ll diff1 = recurse_apples(index + 1, sum1 + weights[index], sum2);
    ll diff2 = recurse_apples(index + 1, sum1, sum2 + weights[index]);
    return min(diff1, diff2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    weights.resize(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << recurse_apples(0, 0, 0) << "\n";
}