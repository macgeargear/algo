#include <iostream>
#include <string>

using namespace std;

bool check(string s, int l, int r) {
    if (l >= r)
        return true;

    int left = 0, right = 0;

    int m = (l + r) / 2;
    for (int i = l; i <= m; i++)
        left += s[i] == '1';
    for (int i = m + 1; i <= r; i++)
        right += s[i] == '1';

    if (abs(left - right) > 1)
        return false;

    return check(s, l, m) && check(s, m + 1, r);
}

int main() {
    int n, k;
    cin >> n >> k;
    int len = 1 << k;

    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < len; j++) {
            char c;
            cin >> c;
            s += c;
        }
        cout << (check(s, 0, s.size() - 1) ? "yes\n" : "no\n");
    }
}
