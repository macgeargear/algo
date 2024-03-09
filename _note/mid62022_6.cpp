#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &x) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "\n";
}

void recur(int n, int m, int curr_sum, vector<int> &x) {
    if (curr_sum < 0)
        return;
    if (n == 0) {
        if (curr_sum == 0)
            display(x);
        return;
    }
    for (int i = 1; i <= m; i++) {
        x.push_back(i);
        recur(n - 1, m, curr_sum - i, x);
        x.pop_back();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> x;
    recur(n, m, m, x);
}
