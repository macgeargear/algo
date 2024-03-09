#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int n, vector<int> &v) {
    if (n == 1)
        return v;  // H1v = v

    int m = n / 2;
    vector<int> v_top(v.begin(), v.begin() + m);
    vector<int> v_bottom(v.begin() + m, v.end());

    vector<int> top_res = solve(m, v_top);
    vector<int> bottom_res = solve(m, v_bottom);

    vector<int> res(n);
    for (int i = 0; i < m; i++) {
        res[i] = top_res[i] + bottom_res[i];
        res[i + m] = top_res[i] - bottom_res[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    vector<int> res = solve(n, v);
    for (int &x : res)
        cout << x << " ";
}
