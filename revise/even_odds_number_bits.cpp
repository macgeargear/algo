#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<bool> used;

void solve(int step, int cnt) {
    if (step == n) {
        if (cnt % 2 != 0) {
            for (int i = 0; i < v.size(); i++)
                cout << v[i];
            cout << "\n";
        }
        return;
    } else {
        v[step] = 0;
        solve(step + 1, cnt);
        v[step] = 1;
        solve(step + 1, cnt + 1);
    }
};

int main() {
    cin >> n;
    v.resize(n);
    used.resize(n);
    solve(0, 0);
}
