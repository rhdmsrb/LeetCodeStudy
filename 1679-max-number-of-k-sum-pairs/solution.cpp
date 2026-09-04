class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        sort(nums.begin(), nums.end());
        while (left < right) {
            if (k == nums[left] + nums[right]) {
                left++;
                right--;
                count++;
            } else if (nums[left] + nums[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};
