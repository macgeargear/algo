#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++) {
        int arrive_time, wait_time;
        cin >> arrive_time >> wait_time;
        cows.emplace_back(arrive_time, wait_time);
    }
    int total_time = 0;
    sort(all(cows));
    for (auto &[arrive, wait] : cows) {
        total_time = max(total_time, arrive) + wait;
    }
    cout << total_time << '\n';
}
