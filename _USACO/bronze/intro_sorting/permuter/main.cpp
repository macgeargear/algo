#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

vector<int> A,B;
ll ans=2e9;

ll compute(vector<int> a, vector<int> b) {
    ll res=0;
    for (int i=0; i<a.size(); i++) {
        for (int j=i; j<a.size(); j++) {
            for (int k=i; k<=j; k++) {
                res += a[k] * b[k];
            }
        }
    }
    return res;
}

void permute(vector<int> &sol, vector<bool> &used, int idx) {
    if (idx == sol.size()) {
        ll curr = compute(A,sol);
        ans = min(ans, curr);
    }
    for (int i=0; i<sol.size(); i++) {
        if (!used[i]) {
            sol[idx] = B[i];
            used[i] = true;
            permute(sol, used, idx+1);     
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    A.resize(n);
    B.resize(n);

    for (int &a : A) cin >> a;
    for (int &b : B) cin >> b;

    vector<int> sol(n);
    vector<bool> used(n, false);
    permute(sol, used, 0); 
    cout << ans << "\n";
}

/*
3
5 4 -1
2 3 4

10 + 22 + 18 + 12 + 8 + -4

5 4 -1
3 2 4
15 + 8
*/
