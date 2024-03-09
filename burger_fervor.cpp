#include <iostream>

using namespace std;
// sol1: recursion

// the helper function: solving for the number of minutes
int solve_t(int m, int n, int t) {
    if (t == 0)
        return 0;

    int first, second;
    if (t >= m)
        first = solve_t(m, n, t - m);
    else
        first = -1;

    if (t >= n)
        second = solve_t(m, n, t - n);
    else
        second = -1;

    if (first == -1 && second == -1)
        return -1;

    return max(first, second) + 1;
}

void solve(int m, int n, int t) {
    int result, i;
    result = solve_t(m, n, t);
    if (result >= 0) {
        cout << result;
    } else {
        i = t - 1;
        result = solve_t(m, n, i);
        while (result == -1) {
            i--;
            result = solve_t(m, n, i);
        }
        cout << result;
    }
}

int main() {
}
