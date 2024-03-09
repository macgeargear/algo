#include <cstdio>
#include <iostream>

using namespace std;

// Sol 1: Recursion
// Helper function: Solve for the number of k apples
// return s the mininum cost for buying exactly num_items apples.
double solve_k(int num[], double price[], int num_schemes, double unit_price,
               int num_items) {
    double best, result;
    int i;
    if (num_items == 0)
        return 0;
    else {
        result = solve_k(num, price, num_schemes, unit_price, num_items - 1);
        best = result + unit_price;
        for (int i = 0; i < num_schemes; i++) {
            if (num_items - num[i] >= 0) {
                result = solve_k(num, price, num_schemes, unit_price,
                                 num_items - num[i]);
                best = min(best, result + price[i]);
            }
        }
        return best;
    }
}

#define SIZE 200

double solve(int num[], double price[], int num_schemes, double unit_price,
             int num_items) {
    double best;
    int i;

    best = solve_k(num, price, num_schemes, unit_price, num_items);

    for (int i = num_items + 1; i < SIZE; i++) {
        best = min(best, solve_k(num, price, num_schemes, unit_price, i));
    }
    return best;
}

// ------------------------------------------------------------------------------------

// Sol 2: Memoization

double solve_k_memo(int num[], double price[], int num_schemes,
                    double unit_price, int num_items, double memo[]) {
    double best, result;
    int i;
    if (memo[num_items] != -1)
        return memo[num_items];
    if (num_items == 0) {
        memo[num_items] = 0.0;
        return 0;
    } else {
        result = solve_k_memo(num, price, num_schemes, unit_price,
                              num_items - 1, memo);
        best = result + unit_price;
        for (int i = 0; i < num_schemes; i++) {
            if (num_items - num[i] >= 0) {
                result = solve_k_memo(num, price, num_schemes, unit_price,
                                      num_items - num[i], memo);
                best = min(best, result + price[i]);
            }
        }
        memo[num_items] = best;
        return memo[num_items];
    }
}

double solve_memo(int num[], double price[], int num_schemes, double unit_price,
                  int num_items, double memo[]) {
    double best;
    int i;

    best = solve_k_memo(num, price, num_schemes, unit_price, num_items, memo);

    for (int i = num_items + 1; i < SIZE; i++) {
        best = min(best,
                   solve_k_memo(num, price, num_schemes, unit_price, i, memo));
    }
    return best;
}

int get_number(int *num) {
    int ch;
    int ret = 0;
    ch = getchar();
    while (ch != ' ' && ch != '\n') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    *num = ret;
    return ch == ' ';
}

#define MAX_SCHEMES 20
int main() {
    int test_case, num_schemes, num_items, more, i;
    double unit_price, result;
    int num[MAX_SCHEMES];
    double price[MAX_SCHEMES];
    double memo[SIZE];  // for memoization

    test_case = 0;

    while (scanf("%lf %d", &unit_price, &num_schemes) != -1) {
        test_case++;
        for (int i = 0; i < num_schemes; i++)
            scanf("%d %lf", &num[i], &price[i]);
        scanf(" ");
        printf("Case %d: \n", test_case);
        for (int i = 0; i < SIZE; i++) {
            memo[i] = -1;
        }
        more = get_number(&num_items);
        while (more) {
            result = solve_memo(num, price, num_schemes, unit_price, num_items,
                                memo);
            printf("Buy %d for $%.2f\n", num_items, result);
            more = get_number(&num_items);
        }
        result = solve(num, price, num_schemes, unit_price, num_items);
        printf("Buy %d for %.2f\n", num_items, result);
    }
    return 0;
}
