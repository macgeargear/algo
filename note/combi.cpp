#include <iostream>
#include <vector>

using namespace std;

void combi(int n, vector<int> &sol, int len) {
    if (len == n) {
        for (int &x : sol)
            cout << x << " ";
        cout << "\n";
    } else {
        sol[len] = 0;
        combi(n, sol, len + 1);
        sol[len] = 1;
        combi(n, sol, len + 1);
    }
}

void combi_elm(vector<int> &nums, vector<bool> &used, int round) {
    if (round == nums.size()) {
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                cout << nums[i];
        }
        cout << "\n";
    } else {
        used[round] = false;
        combi_elm(nums, used, round + 1);
        used[round] = true;
        combi_elm(nums, used, round + 1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool> used(n, false);
    vector<int> nums(n, 0);
    for (int &n : nums)
        cin >> n;
    combi_elm(nums, used, 0);
}
