#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> times(n);
  for (int &t : times)
    cin >> t;
  int max_books = 0;
  int curr_time = 0;
  int i = 0, j = 0;
  for (int j = 0; j < times.size(); j++) {
    curr_time += times[i];
    while (curr_time > t) {
      curr_time -= times[i++];
    }
    max_books = max(max_books, j - i + 1);
  }
  cout << max_books;
}
