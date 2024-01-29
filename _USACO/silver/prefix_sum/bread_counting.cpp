#include <iostream>
#include <string>
#include <vector>

using namespace std;

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio();
  if (name.size() != 0) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("bcount");
  int n, q;
  cin >> n >> q;
  vector<int> type1(n + 1), type2(n + 1), type3(n + 1), query(q);
  for (int i = 0; i < n; i++) {
    type1[i + 1] = type1[i];
    type2[i + 1] = type2[i];
    type3[i + 1] = type3[i];

    int type;
    cin >> type;

    switch (type) {
    case 1:
      type1[i + 1]++;
      break;
    case 2:
      type2[i + 1]++;
      break;
    case 3:
      type3[i + 1]++;
      break;
    }
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << type1[b] - type1[a - 1] << " " << type2[b] - type2[a - 1] << " "
         << type3[b] - type3[a - 1] << "\n";
  }
}
