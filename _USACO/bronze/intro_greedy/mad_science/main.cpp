#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;

int main() {
    cin >> n;
    string a,b;
    cin >> a >> b;
    int cnt=0;
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) cnt++;
    }
    cout << cnt;
}
