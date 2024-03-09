#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v, prefix;

int main() {
    cin >> n >> k;
    v.resize(n);
    prefix.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + v[i];

    int max_ans = v[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - i + 1 <= k)
                max_ans = max(max_ans, prefix[j + 1] - prefix[i]);
        }
    }
    cout << max_ans;
}
