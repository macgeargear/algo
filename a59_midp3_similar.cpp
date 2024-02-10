#include <iostream>
#include <string>

using namespace std;

string a, b;
bool check(int n, string &a, string &b) {
    if (a.size() == 1)
        return a[0] == b[0];
    if (a.size() == 2)
        return (a[0] == b[0] && a[1] == b[1]) || (a[1] == b[0] && a[0] == b[1]);

    string left_half_a, right_half_a, left_half_b, right_half_b;
    for (int i = 0; i < n / 2; i++) {
        left_half_a += a[i];
        left_half_b += b[i];
    }
    for (int i = n / 2; i < n; i++) {
        right_half_a += a[i];
        right_half_b += b[i];
    }

    return (check(n / 2, left_half_a, left_half_b) &&
            check(n / 2, right_half_a, right_half_b)) ||
           (check(n / 2, left_half_a, right_half_b) &&
            check(n / 2, right_half_a, left_half_b));
}

int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }
    cout << (check(a.size(), a, b) ? "YES\n" : "NO\n");
}

// njvterun | scwtrfkw
// njtvuner | cstwfrwk
/*
njvt | erun
njtv | uner

nj vt
nj vt

un er
er un

};
*/
