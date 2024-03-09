## partition_2eq_ss
`dp[i][s] = true` when we can from the sum `s` when considering the first `i` items

- the sum `s` can be formed without including the `i` th element, `dp[i-1][s]`
- the sum `s` can be formed including `i` th element, `dp[i-1][s-nums[i]]`
