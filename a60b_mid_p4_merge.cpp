#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &nums, int l, int r, int k) {
    if (k==0) return;
    int mid = (l+r)/2;
    swap(nums[mid-1], nums[mid]);
}

int main() {
    int n,k;
    cin >> n >> k;


}
