#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 7;
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
  vector<ll> first(MOD, -1); // store the first index
  vector<ll> prefix(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    prefix[i + 1] = (prefix[i] + x) % 7;
  }

  ll maximum = 0;
  for (int i = 0; i < prefix.size(); i++) {
    if (first[prefix[i]] == -1)
      first[prefix[i]] = i;
    else {
      maximum = max(maximum, i - first[prefix[i]]);
    }
  }

  cout << maximum;
}
