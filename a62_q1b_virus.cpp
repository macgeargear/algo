#include <iostream>
#include <string>
#include <vector>

using namespace std;

string rev(string a, int l, int r) {
    string s = "";
    for (int i = r; i >= l; i--)
        s += a[i];
    return s;
}

bool is_DOVIC(string virus, int l, int r) {
    if (r - l + 1 == 2)
        return virus[l] == '0' && virus[r] == '1';
    int mid = (l + r) / 2;
    bool check_left = is_DOVIC(virus, l, mid);
    bool check_right = is_DOVIC(virus, mid + 1, r);

    string left_rev = rev(virus, l, mid);
    bool check_left_rev = is_DOVIC(left_rev, 0, left_rev.size() - 1);
    return (check_left && check_right) || (check_left_rev && check_right);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> virus(n);

    for (int i = 0; i < n; i++) {
        string s;
        for (int i = 0; i < 1 << k; i++) {
            char c;
            cin >> c;
            s += c;
        }
        virus[i] = s;
    }

    for (string &v : virus)
        cout << (is_DOVIC(v, 0, v.size() - 1) ? "yes\n" : "no\n");
}
