#include <iostream>
#include <string>

using namespace std;

bool check(int n, string a, string b) {
    if (a.size() == 1)
        return a[0] == b[0];
    if (a.size() == 2)
        return (a[0] == b[0] && a[1] == b[1]) || (a[0] == b[1] && a[1] == b[0]);
    string a_left = a.substr(0, n / 2);
    string a_right = a.substr(n / 2);
    string b_left = b.substr(0, n / 2);
    string b_right = b.substr(n / 2);
    return (check(n / 2, a_left, b_left) && check(n / 2, a_right, b_right)) ||
           (check(n / 2, a_left, b_right) && (check(n / 2, a_right, b_left)));
}

bool check2(int n, string a, string b, int la, int lb) {
    if (n <= 1)
        return a[la] == b[lb];
    int m = n / 2;
    return (check2(m, a, b, la, lb) && check2(m, a, b, la + m, lb + m)) ||
           (check2(m, a, b, la, lb + m) && check2(m, a, b, la + m, lb));
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << (check2(a.size(), a, b, 0, 0) ? "YES\n" : "NO\n");
}
