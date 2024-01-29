#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int l, int r, int target) {
  int mid = (l + r) / 2;
  if (l == r && nums[mid] <= target)
    return nums[mid];
  if (l >= r)
    return -1;
  if (nums[mid] > target)
    return search(nums, l, mid - 1, target);
  return max(nums[mid], search(nums, mid + 1, r, target));
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  vector<int> query(m);
  for (int &n : nums)
    cin >> n;
  for (int &q : query) {
    cin >> q;
    cout << search(nums, 0, n, q) << "\n";
  }
}
