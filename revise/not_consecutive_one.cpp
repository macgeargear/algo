#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

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

int main() {
    int n;
    cin >> n;
    not_consec_ones(n);
    cout << cnt << "\n";
}
