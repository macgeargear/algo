#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int &n : nums) cin >> n;
    // for (int i=0; i<n; i++) {
    //     prefix[i+1] = prefix[i] + nums[i];
    // }

    // left constraint
    for (int i=1; i<n; i++) {
        nums[i] = max(nums[i], nums[i-1] - m); 
    }

    // right constraint
    for (int i=n; i>=1; i--) {
        nums[i-1] = max(nums[i-1], nums[i] - m);
    }

    for (int &n : nums) cout << n << " ";
}

/*
8 3
1 16 4 2 3 8 1 9
---
1 17 21 23 26 34 35 44

| a[i] - a[i+1] | <= m
--- a[i] - a[i+1] <= m

a[i] - a[i+1] >= -m
--- a[i+1] - a[i] <= m
*/
