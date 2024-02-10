#include <iostream>

using namespace std;

int arr[11];

int solve(int n, int idx) {
    if (n < 0)
        return 1e9;
    if (n <= 1)
        return 1;
    int div = n / arr[idx];
    return div * idx + min((solve(n - div * arr[idx], idx - 1)),
                           idx + solve((div + 1) * arr[idx] - n, idx - 1));
}

int main() {
    int n;
    cin >> n;

    arr[1] = 1;
    for (int i = 2; i <= 10; i++) {
        arr[i] = arr[i - 1] * 10 + 1;
    }
    cout << solve(n, 10);
}
