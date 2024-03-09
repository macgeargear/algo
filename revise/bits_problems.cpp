#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int cnt;
void not_consec_ones(int n, string s = "", char lastChar = '0') {
    if (n == 0) {
        cnt++;
        cout << s << "\n";
        return;
    }
    not_consec_ones(n - 1, s + '0', '0');
    if (lastChar == '0') {
        not_consec_ones(n - 1, s + '1', '1');
    }
}

void equal_one_zero(int n, string s = "", int cnt_one = 0, int cnt_zero = 0) {
    if (n == 0) {
        if (cnt_one == cnt_zero)
            cout << s << "\n";
        return;
    }
    equal_one_zero(n - 1, s + '0', cnt_one, cnt_zero + 1);
    equal_one_zero(n - 1, s + '1', cnt_one + 1, cnt_zero);
}

void without_k_consec(int n, int k, string s = "", int consec = 0) {
    if (n == 0) {
        cout << s << "\n";
        return;
    }
    without_k_consec(n - 1, k, s + '0', 0);
    if (consec < k)
        without_k_consec(n - 1, k, s + '1', consec + 1);
}

void palindromic_bit(int i, int n, string s = "") {
    if (i == n / 2) {
        string rev = s.substr(0, n / 2);
        reverse(rev.begin(), rev.end());
        cout << s + rev << "\n";
        return;
    }
    palindromic_bit(i + 1, n, s + '0');
    palindromic_bit(i + 1, n, s + '1');
}

int main() {
    int n, k;
    // cin >> n >> k;
    // equal_one_zero(n);
    // without_k_consec(n, k);
    palindromic_bit(0, 4);
}
