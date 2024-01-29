#include <iostream>
#include <vector>

using namespace std;

const vector<int> I = {1, 0, 0, 1};

vector<int> matrix_multiply(const vector<int> &A,const vector<int> &B,int k) {
    vector<int> res(A.size());
    res[0] = (A[0]*B[0] + A[1]*B[2])%k;
    res[1] = (A[0]*B[1] + A[1]*B[3])%k;
    res[2] = (A[2]*B[0] + A[3]*B[2])%k;
    res[3] = (A[2]*B[1] + A[3]*B[3])%k;
    return res;
}

vector<int> matrix_modulo(vector<int> &A, int n, int k) {
    if (n==1) return matrix_multiply(A, I, k);
    vector<int> A_2 = matrix_modulo(A, n/2, k);
    if (n%2 == 0) return matrix_multiply(A_2, A_2, k);
    return matrix_multiply(A, matrix_multiply(A_2, A_2, k), k);
}

int main() {
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> A = {a,b,c,d};
    vector<int> res = matrix_modulo(A, n, k);
    for (int &x : res) cout << x << " ";
}
