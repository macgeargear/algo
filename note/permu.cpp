#include <iostream>
#include <version>

using namespace std;

void permu(vector<int> nums, vector<int> &sol, int len, vector<bool> &used, vector<vector<int>> &res) {
  if (len == nums.size()) {
    // for (int &x : sol) cout << x << " ";
    // cout << "\n";
    res.push_back(sol);
  } else {
    for (int i=0; i<nums.size(); i++) {
      if (!used[i]) {
        used[i] = true;
        sol[len] = nums[i];
        permu(nums, sol, len+1, used, res);
        used[i] = false;
      }
    }
  }
}

void permu(vector<int> nums, vector<int> &sol, int len, vector<bool> &used, vector<vector<int>> &res, int k) {
  if (len == k) {
    res.push_back(sol);
  } else {
    for (int i=0; i<nums.size(); i++) {
      if (!used[i]) {
        used[i] = true;
        sol[len] = nums[i];
        permu(nums, sol, len+1, used, res);
        used[i] = false;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> sol(n), nums(n);
  vector<vector<int>> res;
  for (int i=0; i<n; i++) 
    cin >> nums[i]; 
  vector<bool> used(n, false);
  permu(nums, sol, 0, used, res);
  for (auto &x : res) {
    for (int &y : x) cout << y << " ";
    cout << "\n";
  }
}
