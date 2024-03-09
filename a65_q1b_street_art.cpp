#include <iostream>
#include <vector>

#define vec vector

using namespace std;

int W, N;
vec<int> Y;

int solve(int a, int b, int c) {
    if (c - b + 1 < 3)
        return c - b + 1;
    int u = (c - b + 1) / 3;
    int v = (c - b + 2) / 3;
    return max({solve(a + 1, b, b + u - 1), solve(a + 2, b + u, b + u + v - 1),
                solve(a + 3, b + u + v, c)});
}

int main() {
    cin >> W >> N;
    Y.resize(N);
    for (int i = 0; i < N; i++)
        cin >> Y[i];
    cout << solve(0, 1, W) << "\n";
}

/*
start: parameter(0, 1, W)
u = (c-b+1)/3
v = (c-b+2)/2
---
p[1] = (a+1, b, b-u-1)
p[2] = (a+2, b+u, b+u+v-1)
p[3] = (a+3, b+u+v, c)
*/
