#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i=0; i<n; i++) {
    cin >> x[i];
  }
  for (int i=0; i<n; i++) {
    cin >> y[i];
  }
  int ans = 0;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      int square = dx*dx + dy*dy;
      ans = max(ans, square);
    }
  }
  cout << ans << "\n";
}
