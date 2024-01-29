#include <iostream>
#include <valarray>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
  if (nums.empty()) return {{}};
  int n = nums.back();
  nums.pop_back();
  vector<vector<int>> res = subsets(nums);

  int size = res.size();
  for (int i=0;i <size; i++) {
    res.push_back(res[i]);
    res.back().push_back(n);
  }

  return res;
}

int main() {
  vector<int> v = {1,2,3};
  vector<vector<int>> ss = subsets(v); 
  for (auto & s : ss) {
    for (auto &x : s) {
      cout << x << " ";
    }
    cout << "\n";
  }
} 
