#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), prefix(n + 1);
    for (int &n : nums)
        cin >> n;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];

    int max_sum = nums[0];
    int curr_sum = nums[0];

    int min_prefix = prefix[0];
    int l = 0, r = 1;
    while (r <= n) {
        // cout << "l: " << l << " "
        //      << "r: " << r << " ";
        // cout << "curr_sum: " << curr_sum << " max_sum: " << max_sum
        //      << " length: " << r - l + 1 << "\n";

        curr_sum = max(curr_sum, prefix[r + 1] - prefix[l]);
        while (r - l + 1 >= m) {
            curr_sum = max(curr_sum, prefix[r + 1] - prefix[l]);
            min_prefix = min(min_prefix, prefix[l]);
            max_sum = max(curr_sum, max_sum);
            l++;
        }
        int tmp = l;
        while (tmp < r) {
            curr_sum = max(curr_sum, prefix[r + 1] - prefix[l]);
            min_prefix = min(min_prefix, prefix[l]);
            max_sum = max(curr_sum, max_sum);
            tmp++;
        }

        max_sum = max(curr_sum, max_sum);
        r++;
    }
    cout << max_sum << "\n";
}
