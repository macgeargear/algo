#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int solve_recur(vector<int> &arr, int target, int l, int r) {
    if (l>r) return r+1;
    int mid = (l+r)/2;
    if (arr[mid] < target) return solve_recur(arr, target, mid+1, r);
    return min(mid, solve_recur(arr, target, l, mid-1));
}

int solve(vector<int> &arr, int target) {
    int l=0, r=arr.size()-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (arr[mid] < target) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return r+1;
}

int solve2(vector<int> &arr, int target) {
    int l=0, r=arr.size()-1, ans=-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (arr[mid] >= target) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    } 
    return ans;
}

int first_not_smaller(std::vector<int> arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    return solve_recur(arr, target, 0, arr.size()-1);
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = first_not_smaller(arr, target);
    std::cout << res << '\n';
}


