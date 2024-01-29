#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
    int n = nums.size(), cnt=0;
    vector<int> prefix(n+1);
    map<int, int> dist;
    for (int &n : nums) cin >> n;
    for (int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + nums[i];
    }

    for (int &p : prefix) {
        if (dist.count(p-k))
            cnt += dist[p-k];
        dist[p]++;
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &n : nums) cin >> n;
    cout << subarraySum(nums, k);
}
