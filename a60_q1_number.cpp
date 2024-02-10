#include <iostream>
using namespace std;

int i = 0;
int cnt = 0;
void solve(int n, int l, int r) {
    if (n == 1 || n == 0) {
        i++;
        if (i > r)
            return;
        if (i >= l && i <= r)
            cnt += n == 1;
        return;
    }

    solve(n / 2, l, r);
    i++;
    if (i > r)
        return;
    if (i >= l && l < r) {
        cnt += n % 2 == 1;
    }
    solve(n / 2, l, r);
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    solve(n, l, r);
    cout << cnt << "\n";
}
