#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio();
    if (name.size() != 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("div7");
    int n;
    cin >> n;
    vector<ll> cows(n);
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i];
        int x;
        cin >> x;
        sum[i + 1] += x;
    }
    int max_consec = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((sum[j] - sum[i - 1]) % 7 == 0)
                max_consec = max(max_consec, j - i + 1);
        }
    }
    cout << max_consec;
}
