#include <iostream>
#include <string>

using namespace std;

string reverse(string a, int l, int r) {
    string s = "";
    for (int i = r; i >= l; i--)
        s += a[i];
    return s;
}

bool check(string s, int l, int r) {
    if (r - l + 1 == 2)
        return s[l] == '0' && s[r] == '1';
    int m = (l + r) / 2;

    bool left = check(s, l, m);
    bool right = check(s, m + 1, r);

    string rev = reverse(s, l, m);
    bool left_rev = check(rev, 0, rev.size() - 1);
    return (left && right) || (left_rev && right);
}

int main() {
    int n, k;
    cin >> n >> k;
    int len = 1 << k;
    for (int i = 0; i < n; i++) {
        string s;
        for (int i = 0; i < len; i++) {
            char c;
            cin >> c;
            s += c;
        }
        cout << (check(s, 0, s.size() - 1) ? "yes\n" : "no\n");
    }
}
