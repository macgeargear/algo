#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
void backtrack(vector<int> &nums, int start, vector<int> &path) {
  res.push_back(path);
  for (int i=start; i<nums.size(); i++) {
    path.push_back(nums[i]);
    backtrack(nums, i+1, path);
    path.pop_back();
  }
}

int main() {
  vector<int> v = {1,2,3}, path;

  backtrack(v, 0, path);
  for (auto & s : res) {
    for (auto &x : s) {
      cout << x << " ";
    }
    cout << "\n";
  }
} 
