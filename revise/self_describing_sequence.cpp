#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    if (n == 1)
        return 1;
    return 1 + solve(n - solve(solve(n - 1)));
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << solve(x);
    }
}
