class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, val = nums[0];
        for ( int i = 1 ; i < nums.size(); ++i ) 
            if ( nums[i] != val ) {
                if ( cnt == 1 )  val = nums[i];
                else --cnt;
            }
            else ++cnt;
        return val;
    }
};