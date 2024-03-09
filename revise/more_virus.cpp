#include <cmath>
#include <iostream>

using namespace std;

// problem 2: Encryption Wave Detection
// An encryption algorithm uses a wave pattern in binary sequences, identifiable
// by alternating '1's and '0's with a twist: the sequence can start with any
// number of '1's followed by an equal number of '0's and then repeats (e.g.,
// "111000111000").
bool is_secure(const string& seq) {
    int i = 0, n = seq.size();
    while (i < n) {
        int ones = 0, zeros = 0;
        while (i < n && seq[i] == '1') {
            ones++;
            i++;
        }
        while (i < n && seq[i] == '0') {
            zeros++;
            i++;
        }
        if (ones != zeros)
            return false;
    }
    return true;
}

// problem 3: Genetic Trait Tracker
// the sequence contains an even number of '1's,
// and there are no more than two consecutive '1's or '0's.
bool has_trait(string s) {
    return false;
}

// problme 3.1: Gen Trait

// problem 4: advanced virus detection
bool detection(string s) {
    int n = s.size();
    if (n % 2 != 0)
        return false;
    string left = s.substr(0, n / 2);
    string right = s.substr(n / 2);

    if (left != string(right.rbegin(), right.rend()))
        return false;

    int count_left_ones = count(left.begin(), left.end(), '1');
    int count_right_ones = count(right.begin(), right.end(), '1');
    return count_left_ones % 2 == 1 && count_left_ones % 2 == 1;
}

// ไวรัสขนาดเล็กที่สุดมีรหัสพันธุกรรมขนาด 3 และมีรหัสพันธุกรรมอยู่สามแบบคือ ‘000’, ‘111’, และ
// ‘222’ ไวรัสขนาด 3^k จะเกิดจากไวรัสขนาด 3^(k-1) สามตัวมาต่อกัน โดย a, b, และ c
// คือรหัสพันธุกรรมของไวรัสขนาด 3^(k-1) ที่นำมาต่อกันเป็นไวรัสขนาด 3^k การต่อกันนี้จะมีกฎสำคัญคือ,
// จำนวนตัวเลขในแต่ละกลุ่ม (0, 1, หรือ 2) ภายใน a, b, และ c ต้องมีความหลากหลายไม่เกิน 1
// ตัวในแต่ละกลุ่ม
bool check_genome(string s, int k) {
    int n = s.size();
    int l = pow(3, k);
    if (n != l)
        return false;

    if (k == 0)
        return true;

    int part_len = pow(3, k - 1);
    for (int i = 0; i < n; i += part_len) {
        if (!check_genome(s.substr(i, part_len), k - 1))
            return false;
    }
    int count[3] = {0};
    for (char c : s) {
        if (c < '0' || c > '2')
            return false;
        count[c - '0']++;
    }
    if (abs(count[0] - count[1]) > 1 || abs(count[1] - count[2]) > 1 ||
        abs(count[2] - count[0]) > 1)
        return false;
    return true;
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        string genome;
        cout << "Enter genome #" << i + 1 << ": ";
        cin >> genome;

        if (check_genome(genome, k)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
