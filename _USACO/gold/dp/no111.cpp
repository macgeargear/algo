#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
}

/*
**example**
n = 4
HTTT TTTH TTTT
---
### case 1: i'th position is T
-


dp[i][2] = dp[i-1][0] + dp[i-1][3]
*/
