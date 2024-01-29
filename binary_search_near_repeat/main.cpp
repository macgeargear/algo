#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int l, int r, int target) {
  int mid = (l + r) / 2;
  if (l == r && nums[mid] <= target)
    return mid;
  if (l >= r)
    return -1;
  if (nums[mid] > target) {
    return search(nums, l, mid - 1, target);
  }
  return max(mid, search(nums, mid + 1, r, target));
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n), query(m);
  for (int &n : nums)
    cin >> n;
  for (int &q : query)
    cin >> q;
  for (int &q : query)
    cout << search(nums, 0, n - 1, q) << "\n";
}
