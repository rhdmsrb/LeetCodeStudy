# 334. Increasing Triplet Subsequence

Given an array, determine whether there exist indices `i < j < k` such that
`nums[i] < nums[j] < nums[k]`.

## Approach

Track two running values in a single pass:

- `first` — smallest number seen so far
- `second` — smallest number seen so far that is still bigger than *some*
  earlier number (best candidate for the triplet's middle value)

For each new number: if it's `<= first`, it becomes the new `first`. Else if
it's `<= second`, it becomes the new `second`. Otherwise it's bigger than
both, and a valid triplet exists — return true immediately.

The key thing that makes this work even though `first` gets overwritten
freely: once `second` is set, it was set using the `first` that existed at
that moment, so the fact that *some* valid earlier pair `nums[i] < nums[j]`
exists is locked in — overwriting `first` afterward doesn't undo that.

## Complexity

- Time: O(n)
- Space: O(1)

## Notes

Big improvement over the O(n²) pairwise check, and doesn't need the O(n log n)
sorted-structure approach either — one pass, two variables.
