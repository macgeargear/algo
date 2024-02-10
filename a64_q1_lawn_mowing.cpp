#include <ios>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> nums(n), prefix(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        ll sum = 0, ans = 0;
        int l = a, r = n;

        while (l <= r) {
            int mid = (l + r) / 2;
            ll price = (mid - a + 1) * k;
            ll curr_sum = prefix[mid + 1] - prefix[a];
            if (curr_sum + price > b) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            if (curr_sum + price <= b)
                ans = max(ans, curr_sum);
        }
        cout << ans << "\n";
    }
}
