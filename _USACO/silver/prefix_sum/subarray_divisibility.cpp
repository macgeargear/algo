#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> div(n);
  ll pf = 0;
  div[pf] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pf += x;
    div[(pf % n + n) % n]++;
  }

  ll ans = 0;
  for (ll x : div) {
    ans += x * (x - 1) / 2;
  }
  cout << ans;
}
