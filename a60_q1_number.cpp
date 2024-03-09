#include <iostream>
using namespace std;
using ll = long long;

int size(int n) {
    if (n <= 1)
        return 1;
    return size(n / 2) + 1 + size(n / 2);
}

int cnt = 0;
int solve(int n, int l, int r) {
    int s = size(n / 2);
    if (l > r)
        return 0;
    if (n == 1)
        return 1;
    if (r <= s)
        return solve(n / 2, l, r);
    if (l >= s + 2)
        return solve(n / 2, l - s + 1, r - s - 1);
    return n % 2 + solve(n / 2, l, s) + solve(n / 2, 1, r - s - 1);
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
}
