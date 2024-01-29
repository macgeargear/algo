#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
        A[i] *= (i+1) * (n-i); // number of A[i] occur in eq.
    }
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<ll>());

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += A[i] * B[i];
    }

    cout << ans << "\n";
}
