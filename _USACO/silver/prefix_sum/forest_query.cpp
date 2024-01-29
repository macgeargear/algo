#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE=1000;
int main() {
    int n,m;
    cin >> n >> m;

    int tree[MAX_SIZE+1][MAX_SIZE+1];
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) {
            char c;
            cin >> c;
            tree[i+1][j+1] = c == '*';
        }
    
    vector<vector<int>> prefix(n+1, vector<int>(n+1));
    // build prefix matrix
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            prefix[i][j] = tree[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        }
    }

    for (int i=0; i<m; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << "\n";
    }
}
