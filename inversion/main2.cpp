#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void merge(vector<int> &v, int start, int mid, int end, vector<int> &tmp) {
    int i = start;
    int j = mid + 1;
    for (int k = start; k <= end; k++) {
        if (i > mid)
            tmp[k] = v[j++];
        else if (j > end)
            tmp[k] = v[i++];
        else if (v[i] <= v[j])
            tmp[k] = v[i++];
        else {
            tmp[k] = v[j++];
            cnt += mid - i + 1;
        }
    }
    for (int i = start; i <= end; i++)
        v[i] = tmp[i];
}

void merge_sort(vector<int> &v, int start, int end, vector<int> &tmp) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(v, start, mid, tmp);
        merge_sort(v, mid + 1, end, tmp);
        merge(v, start, mid, end, tmp);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums)
        cin >> n;
    vector<int> tmp(n);
    merge_sort(nums, 0, n - 1, tmp);
    cout << cnt;
}
