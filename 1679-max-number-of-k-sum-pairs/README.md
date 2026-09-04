# 1679. Max Number of K-Sum Pairs

Given an array `nums` and target `k`, find the maximum number of operations
where each operation picks two numbers summing to `k` and removes them.

## Approach

Sort `nums` first, then use two pointers starting at opposite ends
(`left = 0`, `right = nums.size() - 1`):

- If `nums[left] + nums[right] == k`, that's a valid pair — count it and move
  both pointers inward.
- If the sum is too small, move `left` forward (sorted order guarantees this
  increases the sum).
- If the sum is too big, move `right` backward (decreases the sum).

Sorting is required for this to work at all — the pointer movement logic
relies on "moving `left` forward always increases the value, moving `right`
backward always decreases it," which is only true once the array is in
non-decreasing order.

## Complexity

- Time: O(n log n) — dominated by the sort; the two-pointer scan itself is O(n)
- Space: O(1) extra (in-place sort aside)

## Notes

First attempt started both pointers near the front (`left=0`, `right=1`) and
only moved them forward together — not actually the two-pointer pattern,
closer to checking adjacent pairs, which misses valid pairs that aren't next
to each other.

Second attempt fixed the pointer setup (opposite ends, correct move-on-sum
logic) but skipped `sort()`. Counterexample that exposes it:
`nums = [4,1,3,2]`, `k = 5` — correct answer is 2 (`{4,1}` and `{3,2}`), but
without sorting, `right` gets pushed past the `{3,2}` pair before `left` ever
moves, giving 1 instead of 2. Adding `sort(nums.begin(), nums.end())` before
the loop fixes it.
