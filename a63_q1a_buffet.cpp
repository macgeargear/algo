#include <algorithm>
#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int n, K, m;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> K >> m;
    vec<int> del(n), pf(n + 1);
    for (int i = 0; i < n; i++)
        cin >> del[i];
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + del[i - 1] - m;

    while (K--) {
        int start, want;
        cin >> start >> want;
        start--;
        int idx =
            lower_bound(pf.begin() + start - 1, pf.end(), pf[start] + want) -
            pf.begin();
        cout << idx << "\n";
    }
}
