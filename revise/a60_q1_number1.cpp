#include <iostream>

using namespace std;

int len(int n) {
    if (n <= 1)
        return 1;
    return 1 + 2 * len(n / 2);
}

int solve(int n, int l, int r, int ql, int qr) {
    printf("%d %d %d %d %d\n", n, l, r, ql, qr);
    if (r < ql || qr < l)
        return 0;
    if (n == 1)
        return 1;
    int m = (l + r) / 2;
    int left = solve(n / 2, l, m - 1, ql, qr);
    int right = solve(n / 2, m + 1, r, ql, qr);
    int mid = (ql <= m && m <= qr && n % 2 == 1);
    return left + mid + right;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, 1, len(n), l, r);
}
