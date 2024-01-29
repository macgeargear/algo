#include <iostream>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    int x, y, m;
    cin >> x >> y >> m;

    int max_milk = 0;
    int max_milk_x = m / x;
    while (max_milk_x >= 0) {
        int max_milk_y = (m - x * max_milk_x) / y;
        while (max_milk_y >= 0) {
            int milk = x * max_milk_x + y * max_milk_y;
            if (milk <= m) {
                max_milk = max(max_milk, milk);
            }
            max_milk_y--;
        }
        max_milk_x--;
    }

    freopen("pails.out", "w", stdout);
    cout << max_milk << "\n";
}

// in 17 25 77
// out 76
