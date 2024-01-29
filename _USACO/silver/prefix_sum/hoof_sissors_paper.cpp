#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> gestures(n);
  for (string &s : gestures)
    cin >> s;
}
