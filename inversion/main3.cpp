#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums, int l, int r, vector<int> &tmp) {
  if (l >= r)
    return 0;
  int cnt = 0;
  int mid = (l + r) / 2;
  cnt += solve(nums, l, mid, tmp);
  cnt += solve(nums, mid + 1, r, tmp);

  int i = l, j = mid + 1;
  for (int k = l; k <= r; k++) {
    if (j > r)
      tmp[k] = nums[i++];
    else if (i > mid)
      tmp[k] = nums[j++];
    else if (nums[i] <= nums[j]) {
      tmp[k] = nums[i++];
    } else {
      tmp[k] = nums[j++];
      cnt += mid - i + 1;
    }
  }
  for (int i = l; i <= r; i++)
    nums[i] = tmp[i];

  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n), tmp(n);
  for (int &n : nums)
    cin >> n;
  cout << solve(nums, 0, n - 1, tmp);
}
