#include <iostream>
#include <vector>

using namespace std;

void solve(int n, vector<int> &mat, vector<int> &ans) {
    if (n == 1) {
        ans[0] = mat[0];
        return;
    }

    if (n == 2) {
        ans = {1, 1, 1, -1};
        return;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> mat(n);
    for (int &m : mat)
        cin >> m;
}
