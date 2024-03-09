### the value you can make
`dp[i][j][k]==true` iff there exist a subset of the first `i` coins with sum `j`, that has a subset with sum k.

- `dp[i-1][j][k]` The i-th coin is not used in the subsets.
- `dp[i-1][j-c_i][]` The i-th coin is used in the subset to make j, but it's not used in the subset of this subset.
- `dp[i-1][j-c_i][k-c_i]` The i-th coin is used in both subsets.
