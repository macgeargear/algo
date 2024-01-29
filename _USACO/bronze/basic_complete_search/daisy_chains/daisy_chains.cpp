#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> daisy(n);
    for (int &d : daisy)
        cin >> d;
    int valid_photos = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double avg = 0;
            for (int k = i; k <= j; k++)
                avg += daisy[k];
            avg /= j - i + 1;
            for (int k = i; k <= j; k++) {
                if (daisy[k] == avg) {
                    valid_photos++;
                    break;
                }
            }
        }
    }
    cout << valid_photos;
}