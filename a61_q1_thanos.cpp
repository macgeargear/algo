#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

ll A,B;
ll attack(vector<ll> &nums, int l, int r) {
    ll range = (upper_bound(all(nums), r) - nums.begin()) - (lower_bound(all(nums), l) - nums.begin());
    if (range==0) return A;
    ll curr = (r-l+1) * range * B;
    if (l==r) return curr; 
    ll mid = (r+l)/2;
    return min(curr, attack(nums, l, mid) + attack(nums, mid+1, r));
}

int main() {
    int p,k,A,B;
    cin >> p >> k >> A >> B;
    int n = (1 << p);
    vector<ll> nums(k);
    for (int i=0; i<k; i++) {
        int x; cin >> x;
        nums[i] = x-1;
    }
    sort(all(nums));
    cout << attack(nums, 0, n-1);
}
