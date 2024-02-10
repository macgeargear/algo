#include <iostream>

using namespace std;

int len(int k) {
    if (k == -1)
        return 0;
    int curr = len(k - 1);
    return curr + (k + 3) + curr;
}

char solve(int n, int k) {
    if (n > len(k))
        return solve(n, k + 1);
    if (n <= len(k - 1))
        return solve(n, k - 1);

    n -= len(k - 1);
    if (n <= k + 3)
        return (n == 1) ? 'g' : 'a';
    n -= k + 3;
    return solve(n, k);
}

int main() {
    int n;
    cin >> n;
    cout << solve(n, 0);
}
