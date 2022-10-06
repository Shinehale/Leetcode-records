class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rv(nums.size(), 1);
        int sum = 1;
        for ( int i = 1; i < nums.size(); ++i ) rv[i] = rv[i - 1] * nums[i - 1];
        for ( int i = nums.size() - 2; i >= 0; --i ) {
            sum = sum * nums[i + 1];
            rv[i] = rv[i] * sum;
        }
        return rv;
    }
};
// 时间O(n) 空间O(1)