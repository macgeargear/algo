#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    map<int, map<int, int>> practices;
    for (int i = 0; i < n; i++) {
        vector<int> sessions(k);
        for (int i = 0; i < k; i++) {
            cin >> sessions[i];
        }
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                practices[sessions[i]][sessions[j]]++;
            }
        }
    }
    for (auto& [cow, others] : practices) {
        for (auto& [cow, win] : others) {
            if (win == n)
                cnt++;
        }
    }
    cout << cnt;
}

/*
3 4
4 1 2 3
4 1 3 2
4 2 1 3
---
(1,4), (2,4), (3,4), (1,3)
*/