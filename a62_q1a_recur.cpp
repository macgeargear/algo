#include <iostream>
#include <vector>

#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

vvi build(int idx, int a, int b, vvi &curr) {
    if (idx == a)
        return curr;

    int len = curr.size();
    curr.resize(len * 2);

    for (int i = 0; i < len; i++) {
        curr[i].resize(len * 2);
        for (int j = len; j < curr.size(); j++)
            curr[i][j] = curr[i][j - len] - 1;
    }

    for (int i = len; i < curr.size(); i++) {
        curr[i].resize(len * 2);
        for (int j = 0; j < len; j++)
            curr[i][j] = curr[i - len][j] + 1;
        for (int j = len; j < curr.size(); j++)
            curr[i][j] = curr[i - len][j - len];
    }

    return build(idx + 1, a, b, curr);
}

int mat[256][256];
void build2(int i, int j, int a, int b) {
    if (a == 0) {
        mat[i][j] = b;
        return;
    }

    int mid = 1 << (a - 1);
    build2(i, j, a - 1, b);
    build2(i + mid, j + mid, a - 1, b);
    build2(i, j + mid, a - 1, b - 1);
    build2(i + mid, j, a - 1, b + 1);
}

int main() {
    int a, b;
    cin >> a >> b;
    vvi curr = {{b}};
    // vvi matrix = build(0, a, b, curr);
    build2(0, 0, a, b);
    // for (auto &row : mat) {
    //     for (auto &x : row)
    //         cout << x << " ";
    //     cout << "\n";
    // }
    for (int i = 0; i < 1 << a; i++) {
        for (int j = 0; j < 1 << a; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}
