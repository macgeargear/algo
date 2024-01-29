#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n *= 2;
    vector<int> people(n);
    for (int &p : people)
        cin >> p;
    int ans = INT32_MAX;
    sort(all(people));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> temp;
            int curr = 0;
            for (int k = 0; k < n; k++)
                if (k != i && k != j)
                    temp.push_back(people[k]);
            for (int i = 0; i < n - 2; i += 2)
                curr += temp[i + 1] - temp[i];
            ans = min(ans, curr);
        }
    }
    cout << ans << "\n";
}