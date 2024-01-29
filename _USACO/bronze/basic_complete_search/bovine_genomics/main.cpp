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
    vector<vector<char>> spotty(m);
    vector<vector<char>> plain(m);
    int cnt = 0;
    // splotty
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            spotty[i].push_back(c);
        }
    }

    // plain
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            plain[i].push_back(c);
        }
    }

    vector<set<char>> spotty_genes(m);
    vector<set<char>> plain_genes(m);
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            spotty_genes[i].insert(spotty[j][i]);
            plain_genes[i].insert(plain[j][i]);
        }
        for (int j = 0; j < n; j++) {
            if (plain_genes[i].find(spotty[j][i]) != plain_genes[i].end()) {
                found = true;
                break;
            }
        }
        if (!found)
            cnt++;
    }
    cout << cnt << "\n";
}