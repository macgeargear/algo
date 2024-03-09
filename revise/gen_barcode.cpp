#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<bool> used;

int n, k;

void combi(int step, int cnt) {
    if (step == n) {
        for (int &x : v)
            cout << x;
        cout << "\n";
    } else {
        if (step - cnt < n - k) {
            v[step] = 0;
            combi(step + 1, cnt);
        }
        if (cnt < k) {
            v[step] = 1;
            combi(step + 1, cnt + 1);
        }
    }
}

int main() {
    cin >> k >> n;
    v.resize(n);
    used.resize(n);
    combi(0, 0);
}
