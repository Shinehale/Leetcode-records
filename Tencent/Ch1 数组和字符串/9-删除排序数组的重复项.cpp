class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int maxValue = 1e4 + 7;
        nums.push_back( maxValue );
        int ptr = 0;
        if ( nums.size() <= 1 ) return nums.size();
        for ( auto i = 0; i < nums.size() - 1; ++i ){
            if ( nums[i] == nums[i + 1] ) continue;
            else {
                nums[ ptr ] = nums[i];
                ++ptr;
            }
        }
        nums.pop_back();
        return ptr;
    }
};
// 时间 O(n) 空间 O (1)