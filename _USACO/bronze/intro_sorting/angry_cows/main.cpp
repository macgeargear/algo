#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("angry.in","r", stdin);
    // freopen("angry.out","w", stdout);

    int n;
    cin >> n;
    vector<int> hay(n);
    for (int &h:hay) cin >> h;
    sort(all(hay));

    int max_flamed=0;
    for (int i=0; i<n; i++) {
        int curr_flamed=1;
        int radius=1;
        int flamed_hay=hay[i];

        // check left
        int l=i-1;
        while (true) {
            int flame_length = flamed_hay - radius;
            if (l < 0 || flame_length > hay[l]) {
                break;
            }
            while (hay[l] > flame_length) {
                l--;
                flamed_hay = hay[l];
                curr_flamed++;
            }
            radius++;
        }

        // check right
        int r=i+1;
        radius=1;
        flamed_hay=hay[i];
        while (true) {
            int flame_length = flamed_hay + radius;
            if (r>n || flame_length < hay[r]) {
                break;
            }
            while (hay[r] < flame_length) {
                flamed_hay = hay[r];
                r++;
                curr_flamed++;
            }
            radius++;
        }

        // for (int l=i-1; l>=0; l--) {
        //     if (flamed_hay-radius <= hay[l]) {
        //         curr_flamed++;
        //         flamed_hay=hay[l];
        //     } else {
        //         break;
        //     }
        //     radius++;
        // }

        // int left = curr_flamed;
        // radius=1;
        // flamed_hay=hay[i];
        // for (int r=i+1; r<n; r++) {
        //     if (flamed_hay+radius >= hay[r]) {
        //         curr_flamed++;
        //         flamed_hay=hay[r];
        //     } else {
        //         break;
        //     }
        //     radius++;
        // }

        max_flamed = max(max_flamed, curr_flamed);
    }
    cout << max_flamed << "\n";
}

/*
8
5
6
13
3
4

r=0
_ _ _ x x ! x _ x _ _ _ _ x
r=1
_ _ _ x ! ! ! _ x _ _ _ _ x
r=2
_ _ ! ! ! ! ! ! ! _ _ _ _ x

*/
