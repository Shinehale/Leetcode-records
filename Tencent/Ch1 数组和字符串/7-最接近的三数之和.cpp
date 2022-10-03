class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if ( nums.size() < 3 ) return 0; 
        int ans = nums[0] + nums[1] + nums[2];
        for ( auto i = 0; i < nums.size(); ++i ){
            int left = i + 1, right = nums.size() - 1;
            while ( left < right ){
                int sum = nums[left] + nums[right] + nums[i];
                if ( abs( sum - target ) < abs( ans - target )) ans = sum;
                if ( sum > target ) --right  ;
                else if ( sum < target ) ++left;
                else break;
            }
            if ( ans == target ) break;
        }
        return ans;
    }
};
// 还是双指针，并且复杂度为O(n^2)