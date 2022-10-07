class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int left = 0, right = 0, sum = ans ;
        for ( int i = 1; i < nums.size(); ++i ) {
            if ( nums[i] > nums[right] ) {
                ++right;
                sum += nums[right];
            }else {
                ans = max( ans, sum );
                left = right = i;
                sum = nums[i];
            }
        }
        ans = max( ans, sum );
        return ans;
    }
};
//O(n)