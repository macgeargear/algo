#include <iostream>
#include <vector>

using namespace std;

bool is_infect(string virus, int l, int r, int &cnt_left, int &cnt_right) {
    if (r-l+1 == 2) return abs(cnt_left - cnt_right) <= 1; 
    
    int mid = (l+r) / 2;
    
    for (int i=l; i<mid; i++) 
        cnt_left += virus[i] == '1';
    for (int i=mid+1; i<r; i++) 
        cnt_right += virus[i] == '1';

    bool check_left = is_infect(virus, l, mid, cnt_left, cnt_right);
    bool check_right = is_infect(virus, mid+1, r, cnt_left, cnt_right);

    return check_left && check_right && abs(cnt_left - cnt_right) <= 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> virus(n);
    for (int i=0; i<n; i++) {
        string s;
        for (int i=0; i< 1<<k; i++) {
            char c; cin >> c;
            s += c;
        }
        virus[i] = s;
    }

    for (auto &v : virus) {
        int cnt_left=0, cnt_right=0;
        is_infect(v, 0, v.size()-1, cnt_left, cnt_right);
        cout << (abs(cnt_left-cnt_right) <= 1 ? "yes\n" : "no\n"); 
    }
    // for (auto &v : virus) cout << v << "\n";
}

/*
5 2
0 0 0 0
0 0 1 1
0 1 1 1
1 0 0 0
0 1 0 1
*/

