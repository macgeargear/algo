#include <iostream>
#include <vector>

#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> ans;

bool is_sorted(vector<int> &nums, int l, int r) {
  for (int i = l; i <= r - 1; i++) {
    if (nums[i] > nums[i + 1])
      return false;
  }
  return true;
}

void solve()

    int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n), tmp(n, 0), sol(n, 0);
}
