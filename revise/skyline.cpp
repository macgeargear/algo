#include <iostream>
#include <vector>

#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;

void update(int x, int y, vvi &res) {
    if (res.empty() || (res.back()[0] != x && res.back()[1] != y)) {
        vi coord{x, y};
        res.emplace_back(coord);
    } else {
        res.back()[1] = y;
    }
}

vvi merge(vvi left, vvi right) {
    vvi res;
    int cur_x = 0, cur_y = 0;
    int i1 = 0, i2 = 0;
    int ly = 0, ry = 0;
    while (i1 < left.size() && i2 < right.size()) {
        int x1 = left[i1][0], y1 = left[i1][1];
        int x2 = right[i2][0], y2 = right[i2][1];
        if (x1 < x2) {
            i1++;
            ly = y1;
        } else {
            i2++;
            ry = y2;
        }
        cur_x = std::min(x1, x2);
        cur_y = std::max(ly, ry);
        update(cur_x, cur_y, res);
    }
}

int main() {
}
