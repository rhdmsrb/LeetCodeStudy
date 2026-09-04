# 11. Container With Most Water

Given `n` vertical lines, find the two that, together with the x-axis, form
the container holding the most water.

## Approach

Two pointers starting at the far ends of the array (widest possible
container), moving inward. At each step, move whichever pointer points to
the **shorter** line.

Why the shorter one: area is `width * min(height[left], height[right])` — the
shorter line is always the bottleneck. Moving the taller pointer inward only
shrinks the width while the limiting height stays the same or gets worse, so
it can never improve the area. Moving the shorter pointer is the only move
that has a chance of finding a taller line and increasing the bottleneck
height, since width can only shrink from here on.

## Complexity

- Time: O(n) — pointers move toward each other, meeting once
- Space: O(1)
