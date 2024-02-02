#include <iostream>
#include <vector>

using ll = long long;
#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

vector<int> mat;

int solve(ll i, ll j, int n) {
    if (n == 1)
        return mat[2 * i + j];
    ll mid = 1LL << (n - 1);

    // top left
    if (i < mid && j < mid)
        return solve(i, j, n - 1);

    // top right
    else if (i < mid && j >= mid)
        return solve(j - mid, i, n - 1);

    // bottom left
    else if (i >= mid && j < mid)
        return -solve(i - mid, j, n - 1);

    // bottom right
    else
        return -solve(j - mid, i - mid, n - 1);
}

int main() {
    int n, m, u, v, w, p;
    cin >> n >> m;
    cin >> u >> v >> w >> p;
    mat = {u, v, w, p};
    while (m--) {
        ll r, c;
        cin >> r >> c;
        cout << solve(r - 1LL, c - 1LL, n) << "\n";
    }
}
