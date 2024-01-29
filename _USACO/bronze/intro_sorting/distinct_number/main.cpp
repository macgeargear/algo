#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> s;
    while (n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
}