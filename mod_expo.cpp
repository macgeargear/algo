#include <iostream>

using namespace std;

using ll = long long;

ll mod_expo(int x, ll n, int k) {
    if (n==0) return 1;
    ll p = mod_expo(x, n/2, k);
    if (n%2==0) return (p*p) %k;
    return (x*p*p)%k;
}


int main() {
    int x,k;
    ll n;
    cin >> x >> n >> k;
    cout << mod_expo(x, n, k);
}
