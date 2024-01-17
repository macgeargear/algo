#include <iostream>
#include <version>

using namespace std;

void permu_kn_replace(int n, vector<int> &sol, int len, vector<vector<int>> &res, int k) {
  if (len == k) {
    res.push_back(sol);
  } else {
    for (int i=0; i<n; i++) {
        sol[len] = i+1;
        permu_kn_replace(n, sol, len+1, res, k);
      }
    }
  }

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> sol(k);
  vector<vector<int>> res;
  vector<bool> used(n, false);
  permu_kn_replace(n, sol, 0, res, k);
  for (auto &x : res) {
    for (int &y : x) cout << y << " ";
    cout << "\n";
  }
}
