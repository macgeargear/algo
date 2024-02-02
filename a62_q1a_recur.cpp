#include <iostream>
#include <vector>

#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

vvi build(int idx, int a, int b, vvi &curr) {
    if (idx==a) return curr;

    int len = curr.size();
    curr.resize(len*2);

    for (int i=0; i<len; i++) {
        curr[i].resize(len*2);
        for (int j=len; j<curr.size(); j++) 
            curr[i][j] = curr[i][j-len] - 1; 
    }

    for (int i=len; i<curr.size(); i++) {
        curr[i].resize(len*2);
        for (int j=0; j<len; j++) 
            curr[i][j] = curr[i-len][j]+1;
        for (int j=len; j<curr.size(); j++) 
            curr[i][j] = curr[i-len][j-len];
    }

    return build(idx+1, a, b, curr);
}  

int main() {
    int a, b;
    cin >> a >> b;
    vvi curr = {{b}};
    vvi matrix = build(0, a, b, curr);
    for (auto &row: matrix) {
        for (auto &x : row) cout << x << " ";
        cout << "\n";
    }
}
