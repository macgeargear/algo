#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int &n : nums)
        cin >> n;

    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j])
                cnt++;
        }
    }

    cout << cnt;
}
