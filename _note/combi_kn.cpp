#include <iostream>
#include <vector>

using namespace std;

void combi_kn(int n, vector<int> &sol, int len, int k, int chosen) {
  if (len == k) {
    for (auto &x: sol) cout << x << " ";
    cout << "\n";
  } else {
    sol[len] = 0;
    combi_kn(n, sol, len+1, k, chosen);
    if (chosen < k) {
      sol[len] = 1;
      if (chosen < k) {
        combi_kn(n, sol, len+1, k, chosen+1);
      }
    } else {
      for (int i=0; i<n; i++) 
        if (sol[i] == 1)
          cout << i+1 << " ";
      cout << "\n";
    }

  }
}

int main() {
  int n, k;
  cin >> n;
  vector<int> sol(n);
  combi_kn(n, sol, 0, k, 0);
}
