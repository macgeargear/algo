#include <iostream>
#include <vector>

using namespace std;

int n, w, k;

int solve(vector<int> &left, vector<int> &right) {
    vector<int> dp_l(n + 1), dp_r(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     dp_l[i] = left[i - 1];
    //     dp_r[i] = right[i - 1];
    // }
    for (int i = 1; i <= n; i++) {
        if (i - w - 1 >= 0) {
            dp_l[i] += dp_r[i - w - 1];
            dp_r[i] += dp_l[i - w - 1];
        }
        dp_l[i] = max(dp_l[i], dp_l[i - 1]);
        dp_r[i] = max(dp_r[i], dp_r[i - 1]);
    }
    return max(dp_l[n], dp_r[n]);
}

int main() {
    cin >> n >> w >> k;
    vector<int> left(n), right(n);
    for (int &l : left)
        cin >> l;
    for (int &r : right)
        cin >> r;
    cout << solve(left, right) << "\n";
}
