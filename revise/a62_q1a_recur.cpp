#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mat;
void build(int a, int b, int i, int j) {
    if (a == 0) {
        mat[i][j] = b;
        return;
    }
    int m = 1 << (a - 1);
    build(a - 1, b, i, j);
    build(a - 1, b + 1, i + m, j);
    build(a - 1, b - 1, i, j + m);
    build(a - 1, b, i + m, j + m);
}

int main() {
    int a, b;
    cin >> a >> b;
    int n = 1 << a;
    mat = vector<vector<int>>(n, vector<int>(n));
    build(a, b, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}
