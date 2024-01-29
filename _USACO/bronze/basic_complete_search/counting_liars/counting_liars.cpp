#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, string>> cows(n);
    for (auto &[a, b] : cows) {
        cin >> b >> a;
    }
    sort(cows.begin(), cows.end());
    int min_liars = INT_MAX;
    for (int i = 0; i < n; i++) {
        int liars = 0;
        // left
        for (int l = i - 1; l >= 0; l--) {
            if (cows[l].second == "L") {
                liars++;
            }
        }
        // right
        for (int r = i + 1; r < n; r++) {
            if (cows[r].second == "G") {
                liars++;
            }
        }
        min_liars = min(min_liars, liars);
    }
    cout << min_liars;
}