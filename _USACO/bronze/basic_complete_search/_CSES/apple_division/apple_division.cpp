#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> apples, vector<int> &sol, vector<bool> &used,
           size_t round, int &min_diff_apples, int sum_apples) {
    if (round == apples.size()) {
        int group1 = 0;
        for (int i = 0; i < apples.size(); i++) {
            if (used[i]) {
                group1 += apples[i];
            }
        }
        int group2 = sum_apples - group1;
        min_diff_apples = min(min_diff_apples, abs(group1 - group2));
    } else {
        used[round] = 0;
        solve(apples, sol, used, round + 1, min_diff_apples, sum_apples);
        used[round] = 1;
        solve(apples, sol, used, round + 1, min_diff_apples, sum_apples);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> apples(n);
    int sum = 0;
    for (int &a : apples) {
        cin >> a;
        sum += a;
    }
    sort(apples.begin(), apples.end());
    vector<int> sol(n, 0);
    vector<bool> used(n, false);
    int min_diff_apples = INT_MAX;
    solve(apples, sol, used, 0, min_diff_apples, sum);
    cout << min_diff_apples;
}