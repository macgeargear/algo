# Edit distance
### DP state and transition
- let `dp[i][j]` be the minimum edit distance to change from word1[0:i] to word2[0:j]`
- if `word1[i] == word2[j]`, then `dp[i][j] = dp[i-1][j-1]`, because we don't need to change anything

to get `dp[i][j]`, we have 3 options:
1. insert a character to word1: `dp[i][j] = dp[i][j-1] + 1`
2. delete a character from word1: `dp[i][j] = dp[i-1][j] + 1`
3. replace a character in word1: `dp[i][j] = dp[i-1][j-1] + 1`

### base case
- if `i == 0`, then `dp[i][j] = j`
- if `j == 0`, then `dp[i][j] = i`

### transition
`dp[i][j]` = min(insert, delete, replace)

|same|delete  |
|add |dp[i][j]|

```cpp
int min(int a, int b, int c) {
    return min(min(a,b),c);
}

int min_distance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    // base case
    for (int i=0; i<=m; i++) dp[0][i] = i;
    for (int i=0; i<=n; i=+) dp[i][0] = i;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            // same letter
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
        }
    }
    return dp[n][m];
}
```

# 0/1 Knapsack
- Given a list of items with values and weights, as well as a max weight, find the maximum value you can generate by selecting items such that the sum of the weights is less than or equal to the max.

### DP state and transition
- let `dp[i][j]` be the maximum value that can be obtained with items[0:i] and max weight j
- if `weights[i] > j`, then we can't add this item to the knapsack, so `dp[i][j] = dp[i-1][j]`
- if `weights[i] <= j`, then we can add this item to the knapsack, so `dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i])`

### base case
- if `i == 0 || j == 0`, then `dp[i][j] = 0`

### transition
`dp[i][j]` = max(not add, add)

```cpp
int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=W; j++) {
            if (weights[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }
    return dp[n][W];
}
```

# 2D to 1D optimization
- In the knapsack problem, we can see that `dp[i][j]` only depends on `dp[i-1][j]` and `dp[i-1][j-weights[i]]`, so we can optimize the space complexity from `O(n*W)` to `O(W)` by using a 1D array.

```cpp
int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<int> dp(W+1, 0);

    for (int i=1; i<=n; i++) {
        for (int j=W; j>=1; j--) {
            if (weights[i-1] <= j) {
                dp[j] = max(dp[j], dp[j-weights[i-1]] + values[i-1]);
            }
        }
    }
    return dp[W];
}
```

# Coin Change
- Given a list of coins of different denominations and a total amount of money, find the number of ways to make up that amount.

### DP state and transition
- let `dp[i][j]` be the number of ways to make up amount j with coins[0:i]
- if `coins[i] > j`, then we can't add this coin to the amount, so `dp[i][j] = dp[i-1][j]`
- if `coins[i] <= j`, then we can add this coin to the amount, so `dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]`

### base case
- if `i == 0`, then `dp[i][j] = 1` if `j % coins[0] == 0`, else `dp[i][j] = 0`
- if `j == 0`, then `dp[i][j] = 1`

### transition
`dp[i][j]` = add, not add

```cpp
int coin_change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

    for (int i=0; i<=n; i++) dp[i][0] = 1;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=amount; j++) {
            if (coins[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}
```

# Bit string without 101
- Given a positive integer n, return the number of the strings of length n that do not contain "101".

### DP state and transition
- let `dp[i]` be the number of the strings of length i that do not contain "101"
- if `s[i-2:i] == "101"`, then we can't add "101" to the string, so `dp[i] = dp[i-1] + dp[i-2]`
- else, we can add "0" or "1" to the string, so `dp[i] = dp[i-1] + dp[i-2]`

### base case
- `dp[0] = 1`, `dp[1] = 2`
