#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<char>> spotty(n, vector<char>(m));
    vector<vector<char>> plain(n, vector<char>(m));
    int cnt = 0;
    // splotty
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spotty[i][j];
        }
    }

    // plain
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plain[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        set<char> seen;
        for (int j = 0; j < n; j++)
            seen.insert(spotty[j][i]);
        bool dup = false;
        for (int j = 0; j < n; j++) {
            if (seen.find(plain[j][i]) != seen.end()) {
                dup = true;
                break;
            }
        }
        if (!dup)
            cnt++;
    }
    cout << cnt << "\n";
}