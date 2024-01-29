#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;

void backtrack(int n, int k, int start, vector<int> &track) {
  // reach the bottom of tree
  if (k==track.size()) {
    res.push_back(track);
    return;
  }
  // note: i is incremented from start
  for (int i=start; i<=n; i++) {
    track.push_back(i);
    backtrack(n, k, i+1, track);
    track.pop_back();
  }
}

vector<vector<int>> combine(int n, int k) {
  if (k <= 0 || n <= 0) return res;
  vector<int> track;
  backtrack(n, k, 1, track);
  return res;
}



int main() {
  combine(4,2);
  for (auto & s : res) {
    for (auto &x : s) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
