#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int> &v, int start, int mid, int stop, vector<int> &tmp) {
    cout << start << " " << stop << "\n";
    int bi = start, ci = mid+1;
    for (int i=start; i<=stop; i++) {
        if (ci > stop) {tmp[i] = v[bi++]; continue; }
        if (bi > mid) {tmp[i] = v[ci++]; continue; }
        tmp[i] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];
    }
    for (int i=start; i<=stop; i++) v[i] = tmp[i];
}

void merge_sort(vector<int> &v, int start, int stop, vector<int> &tmp) {
    if (start < stop) {
        int mid = (start + stop) >> 1;
        merge_sort(v, start, mid, tmp);
        merge_sort(v, mid+1, stop, tmp);
        merge(v, start, mid, stop, tmp);
    }
}

int main() {
    vector<int> v = {5, 3 ,2 , 4, 1}; 
    vector<int> tmp(v.size());
    merge_sort(v, 0, v.size()-1, tmp);
    cout << "-------\n";
    for (int &x : v) cout << x << " ";
}
