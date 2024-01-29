#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> diamond(n);
    for (int &d : diamond)
        cin >> d;

    sort(diamond.begin(), diamond.end());
    int l = 0, r = 0, mx = 0;
    while (l < n && r < n) {
        while (r < n && diamond[r] - diamond[l] <= k) {
            r++;
        }
        l++;
        mx = max(mx, r - l + 1);
    }

    cout << mx;
}

// 1 1 3 4 6
