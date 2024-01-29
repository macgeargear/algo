#include <iostream>

using namespace std;

bool is_infect(int virus[], int l, int r) {
    if (r-l+1 == 1) return true;

    int cnt_l=0, cnt_r=0;
    int mid = (l+r)/2;

    for (int i=l; i<=mid; i++) 
        if (virus[i]) cnt_l++;
    for (int i=mid+1; i<=r; i++) 
        if (virus[i]) cnt_r++;
    
    if (abs(cnt_l - cnt_r) > 1) return false;
    return is_infect(virus, l, mid) && is_infect(virus, mid+1, r);
}

int main() {
    int n, k;
    cin >> n >> k;

    int virus[n][1<<k];
    for (int i=0; i<n; i++) 
        for (int j=0; j<(1<<k); j++)
            cin >> virus[i][j];

    for (auto &v : virus) 
        cout << (is_infect(v, 0, (1<<k)-1) ? "yes\n" : "no\n"); 
}
