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

void merge(vector<int> &nums, int l, int m, int r, vector<int> &tmp) {
  int i = l;
  int j = m + 1;
  for (int k = 0; k <= r; k++) {
    if (i > m)
      tmp[k] = nums[j++];
    else if (j > r)
      tmp[k] = nums[i++];
    else if (nums[i] < nums[j])
      tmp[k] = nums[i++];
    else
      tmp[k] = nums[j++];
  }
  for (int i = l; i <= r; i++)
    nums[i] = tmp[i];
}

void merge_sort(vector<int> &nums, int l, int r, vector<int> &tmp,
                int &cnt_merge) {
  if (l >= r)
    return;
  // cout << "merge sort " << l << " " << r << "\n";
  cnt_merge++;
  int m = (l + r) >> 1;
  if (!is_sorted(nums, l, m))
    merge_sort(nums, l, m, tmp, cnt_merge);
  if (!is_sorted(nums, m + 1, r))
    merge_sort(nums, m + 1, r, tmp, cnt_merge);
  merge(nums, l, m, r, tmp);
}

void permute(vector<int> &sol, vector<bool> &used, int idx, int k) {
  if (idx == sol.size()) {
    // for (int &s : sol)
    //   cout << s << " ";
    // cout << "\n";
    vector<int> sol_tmp(sol.begin(), sol.end());
    cout << "before sort\n";
    for (int &s : sol_tmp)
      cout << s << " ";
    cout << "\n";
    int cnt_merge = 0;
    vector<int> tmp(sol_tmp.size());
    merge_sort(sol_tmp, 0, sol.size(), tmp, cnt_merge);
    cout << "after sort\n";
    for (int &s : sol_tmp)
      cout << s << " ";
    cout << "\n";
    // if (cnt_merge == k) {
    //   ans.push_back(sol_tmp);
    // }
    // cout << "merge: " << cnt_merge << " times\n";
  } else {
    for (int i = 0; i < sol.size(); i++) {
      if (!used[i]) {
        used[i] = true;
        sol[idx] = i + 1;
        permute(sol, used, idx + 1, k);
        used[i] = false;
      }
    }
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n), tmp(n, 0), sol(n, 0);
  vector<bool> used(n, false);
  permute(sol, used, 0, k);
  // for (auto &v : ans) {
  //   for (int &x : v)
  //     cout << x << " ";
  //   cout << "\n";
  // }
  // vector<int> test = {2, 1, 3};
  // vector<int> tmp(test.size());
  // int cnt_merge = 0;
  // merge_sort(test, 0, test.size() - 1, tmp, cnt_merge);
  // for (int &n : test)
  //   cout << n << " ";
  // cout << "\n";
  // cout << cnt_merge << "\n";
  // cout << cnt_merge;
}
