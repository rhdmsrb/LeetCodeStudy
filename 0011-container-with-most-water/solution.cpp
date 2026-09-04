class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int best = 0;

        while (left < right) {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            best = max(best, width * minHeight);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return best;
    }
};
