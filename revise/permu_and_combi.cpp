#include <iostream>
#include <string>
#include <vector>

using namespace std;

void perm(vector<int> &sol, vector<bool> &used, int step, int n) {
    if (step == n) {
        for (int &x : sol)
            cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            sol[step] = i;
            perm(sol, used, step + 1, n);
            used[i] = false;
        }
    }
}

void perm_kn(vector<int> &sol, vector<bool> &used, int step, int n, int k) {
    if (step == k) {
        for (int i = 0; i < k; i++) {
            cout << sol[i];
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            sol[step] = i + 1;
            perm_kn(sol, used, step + 1, n, k);
            used[i] = false;
        }
    }
}

void combi(int step, int n, string s = "") {
    if (step == n) {
        cout << s << "\n";
        return;
    }
    combi(step + 1, n, s + '0');
    combi(step + 1, n, s + '1');
}

void combi(int step, int n, int k, int cnt = 0, string s = "") {
    if (step == n) {
        if (cnt >= k)
            cout << s << "\n";
        return;
    }
    combi(step + 1, n, k, cnt, s + '0');
    if (cnt < k)
        combi(step + 1, n, k, cnt + 1, s + '1');
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sol(n);
    vector<bool> used(n);
    // perm_kn(sol, used, 0, n, k);
    combi(0, n, k);
}
