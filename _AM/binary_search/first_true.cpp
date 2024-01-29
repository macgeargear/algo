#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int solve(vector<bool> &arr, int l, int r) {
    if (l>r) return (r+1 == arr.size()) ? -1 : r+1;
    int mid = (l+r) / 2;
    if (!arr[mid]) return solve(arr, mid+1, r);
    return min(mid, solve(arr, l, mid-1));
}

int find_boundary(std::vector<bool> arr) {
    // WRITE YOUR BRILLIANT CODE HERE
    return solve(arr, 0, arr.size()-1);
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<bool> arr = get_words<bool>();
    int res = find_boundary(arr);
    std::cout << res << '\n';
}

