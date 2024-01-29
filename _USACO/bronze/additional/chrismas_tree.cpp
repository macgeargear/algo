#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;

void solve() {
    int n, d, h;
    double ans=0;
    cin >> n >> d >> h;
    vector<double> nums(n);
    std::cout << std::fixed << std::setprecision(6);

    for (double &n : nums) cin >> n;

    double area  = 0.5 * d * h;
    vector<pair<double, double>> height(n);

    for (int i=0; i<n; i++) {
        height[i] = make_pair(nums[i], nums[i]+h);
    }

    ans = area * n;
    for (int i=1; i<n; i++) {
        if (height[i].first < height[i-1].second) {
            double new_h = height[i-1].second - height[i].first;
            double new_d = (d*1.0 * new_h) / h;
            ans -= 0.5 * new_h * new_d;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
