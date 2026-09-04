# 443. String Compression

Compress an array of characters in place: each run of consecutive repeated
characters becomes the character followed by its count (count omitted if the
run length is 1). Must use only constant extra space — the result overwrites
`chars` itself.

## Approach

Two pointers: `read` scans forward looking for runs, `write` is where the
compressed output gets placed back into the same array. `write` never gets
ahead of `read`, since the compressed form is never longer than the original,
so it's safe to write into the array being read from.

For each run:

1. Record `start = read`, then advance `read` while the character stays the
   same. `count = read - start` gives the run length.
2. Always write the character once at `write`.
3. If `count > 1`, write its digits. Peeling digits off with `% 10` / `/ 10`
   produces them least-significant-first, so they come out backwards (`12` ->
   `"21"`) — reverse just that digit slice (`digitStart` to `write`) to fix
   the order.

## Complexity

- Time: O(n) — `read` visits each element once
- Space: O(1) extra

## Notes

Two bugs came up while building this that are worth remembering:

- `while (chars[read] == currentChar && read < chars.size())` — `&&` in C++
  short-circuits left to right, so the bounds check has to come **first**.
  Putting the array access before the bounds check still evaluates
  `chars[read]` when `read` is already out of range, which crashed with a
  heap-buffer-overflow on inputs like `["a"]`.
- `chars[read] = currentChar` (single `=`) is assignment, not comparison —
  it silently overwrites data while also making the loop condition always
  truthy, since assignment expressions evaluate to the assigned value.
