#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n), prefix(n + 1);
    map<int, vector<int>> M;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];

    for (int i = 0; i < n; i++) {
        M[nums[i]].push_back(i);
    }

    int max_sum = nums[0];
    for (auto &[k, v] : M) {
        if (v.size() == 1)
            max_sum = max(max_sum, nums[v[0]]);
        else {
            int min_prefix = prefix[v[0]];
            int curr_max = nums[v[0]];
            for (int i = 0; i < v.size(); i++) {
                curr_max = max(curr_max, prefix[v[i] + 1] - min_prefix);
                min_prefix = min(min_prefix, prefix[v[i]]);
            }
            max_sum = max(max_sum, curr_max);

            // for (int i = 0; i < v.size(); i++) {
            //     for (int j = i; j < v.size(); j++) {
            //         max_sum = max(max_sum, prefix[v[j] + 1] - prefix[v[i]]);
            //     }
            // }
        }
    }

    cout << max_sum << "\n";
}
