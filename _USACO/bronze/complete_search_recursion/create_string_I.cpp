#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

void build(int idx, string path, vector<bool> used, string s, set<string> &sol) {
    if (path.size() == s.size()) {
        sol.insert(path);
        return;
    }
    for (int i=0; i<used.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            build(idx+1, path+s[i], used, s, sol);
            used[i] = false;
        }
    }
}

int main() {
    string s;
    cin >> s;
    set<string> sol;
    vector<bool> used(s.size(), false);
    build(0, "", used, s, sol);
    cout << sol.size() << "\n";
    for (auto &s : sol) cout << s << "\n";
}
