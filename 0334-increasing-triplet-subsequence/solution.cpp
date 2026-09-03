class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int n : nums) {
            if (n <= first) {
                first = n;          // new smallest "low point"
            } else if (n <= second) {
                second = n;         // new smallest valid "middle"
            } else {
                return true;        // n is bigger than both -> triplet found
            }
        }
        return false;
    }
};
