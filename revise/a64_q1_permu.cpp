#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v, before;
vector<bool> used;

void permu(int step) {
    if (step == n) {
        for (int &x : v)
            cout << x << " ";
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (used[i] == false && (before[i] == -1 || used[before[i]])) {
                v[step] = i;
                used[i] = true;
                permu(step + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    before = vector<int>(n, -1);
    used.resize(n);
    v.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        before[b] = a;
    }
    vector<int> sol(n);
    vector<bool> used(n, false);
    permu(0);
}
