#include <iostream>
#include <vector>

using namespace std;

vector<int> ones(10);
int solve(int n, int k) {
    if (n == 1 || n == 0)
        return n;
    int div = n / ones[k];
    return div * k + min(solve(n - div * ones[k], k - 1),
                         k + solve((div + 1) * ones[k] - n, k - 1));
}

int main() {
    int n;
    cin >> n;
    ones[1] = 1;
    for (int i = 2; i <= 10; i++) {
        ones[i] = ones[i - 1] * 10 + 1;
    }
    cout << solve(n, 10);
}
