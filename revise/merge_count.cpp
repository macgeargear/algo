#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

void solve(int l, int r, int &k) {
    if (k == 0 || A.back() == -1)
        return;
    if (k < 0) {
        A.back() = -1;
        return;
    }
    if (l + 1 == r || l > r)
        return;
    return;
    int m = (l + r) / 2;
    if (m != 0)
        swap(A[m - 1], A[m]);
    k -= 2;
    solve(l, m, k);
    solve(m, r, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    A.resize(n + 1);
    for (int i = 0; i <= n; i++)
        A[i] = i + 1;
    k--;
    solve(0, n, k);
    if (A[n] == -1 || k != 0) {
        cout << "-1";
        return 0;
    }
    A.pop_back();
    for (auto v : A)
        cout << v << " ";
    return 0;
}
