#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

string s;
set<string> res;
vector<bool> used;

void solve(int i, string path) {
    if (path.size() == s.size()) {
        res.insert(path);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            solve(i + 1, path + s[i]);
            used[i] = false;
        }
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    used.resize(n, false);
    solve(0, "");
    cout << res.size() << "\n";
    for (auto &x : res)
        cout << x << "\n";
}
