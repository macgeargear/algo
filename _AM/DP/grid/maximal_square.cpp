#include <algorithm>  // copy
#include <iostream>   // boolalpha, cin, cout, streamsize
#include <iterator>   // back_inserter, istream_iterator
#include <limits>     // numeric_limits
#include <sstream>    // istringstream
#include <string>     // getline, string
#include <vector>     // vector

using namespace std;

int maximal_square(std::vector<std::vector<int>> matrix) {
    // WRITE YOUR BRILLIANT CODE HERE
    int n = matrix.size();
    int m = matrix[0].size();
    int dp[n][m];
    int best = 0;

    for (int i = 0; i < m; i++) {
        dp[0][i] = matrix[0][i];
        best = max(best, dp[0][i]);
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = matrix[i][0];
        best = max(best, dp[i][0]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] =
                    1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                best = max(best, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return best * best;
}

template <typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{},
              std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
}
