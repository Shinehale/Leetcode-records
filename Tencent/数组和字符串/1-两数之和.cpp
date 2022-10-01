class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        auto length = nums.size();
        for ( int i = 0; i < length; ++i )
            for ( int  j = i + 1; j < length; ++j )
                if ( nums[i] + nums[j] == target ) {
                    ans.push_back( i );
                    ans.push_back( j );
                    break;
                }
        return ans;
    }
};
//  O (n^2) 算法

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        map< int, vector<int> > mp1; 
        int length = nums.size();
        for ( int i = 0; i < length; ++i ){
            mp1[ nums[i] ].push_back( i );
        }
        for ( int i = 0; i < length; ++i ){
            auto res = target - nums[i] ;
            if ( res != nums[i] ){
                if ( mp1[res].size() ) {
                    ans[0] = mp1[res][0] ;
                    ans[1] = mp1[nums[i]][0];
                }
            }else{
                if ( mp1[res].size() > 1 ){
                    ans[0] = mp1[res][0];
                    ans[1] = mp1[res][1];
                }
            }
        }
        return ans;
    }
};
// O(n) 算法