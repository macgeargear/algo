#include <iostream>
#include <map>
#include <vector>

using ll = long long;
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 0, prefix_sum = 0;
  map<ll, int> sums;
  sums[0] = 1;
  vector<int> nums(n);
  for (int &n : nums) {
    cin >> n;
    prefix_sum += n;
    if (sums.count(prefix_sum - k))
      ans += sums[prefix_sum - k];
    sums[prefix_sum]++;
  }

  cout << ans;
}
