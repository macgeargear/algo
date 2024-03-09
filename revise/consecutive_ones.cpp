#include <iostream>

using namespace std;

vector<int> v;
vector<bool> used;
int n, k;

void combi(int step) {
    if (step == n) {
        bool ok = true;
        int cnt = 0;
        int max_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            } else {
                cnt = 0;
            }
        }
        if (max_cnt >= k) {
            for (int &x : v)
                cout << x;
            cout << "\n";
        }
    } else {
        v[step] = 0;
        combi(step + 1);
        v[step] = 1;
        combi(step + 1);
    }
}

int main() {
    cin >> n >> k;
    v.resize(n);
    used.resize(n);
    combi(0);
}
