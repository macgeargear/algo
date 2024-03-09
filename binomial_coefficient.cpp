#include <iostream>

using namespace std;

int topdown(int n, int k) {
    if (n == k || k == 0)
        return 1;
    int res = topdown(n - 1, k) + topdown(n - 1, k - 1);
    return res;
}
int main() {
    int n, k;
    cin >> n >> k;
    cout << topdown(n, k) << "\n";
}
