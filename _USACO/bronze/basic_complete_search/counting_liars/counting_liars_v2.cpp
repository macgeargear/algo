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
    vector<pair<int, char>> cows(n);
    for (auto &[a, b] : cows) {
        cin >> b >> a;
    }
    sort(cows.begin(), cows.end());

    vector<int> left_liars(n), right_liars(n);
    // check for left
    for (int i = 1; i < n; i++) {
        left_liars[i] = left_liars[i - 1];
        if (cows[i - 1].second == 'L') {
            left_liars[i]++;
        }
    }
    // check for right
    for (int i = n - 2; i >= 0; i--) {
        right_liars[i] = right_liars[i + 1];
        if (cows[i + 1].second == 'G') {
            right_liars[i]++;
        }
    }

    int min_liars = INT_MAX;
    for (int i = 0; i < n; i++) {
        min_liars = min(min_liars, left_liars[i] + right_liars[i]);
    }
    cout << min_liars;
}