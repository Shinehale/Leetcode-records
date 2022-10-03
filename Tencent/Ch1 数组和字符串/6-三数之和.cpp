/// 错误的写法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > rv;
        sort( nums.begin(), nums.end() );
        if ( nums.size() < 3 ) return rv;
        auto vb = nums.begin(), ve = --nums.end(), vp = vb;
        while ( *vb != *ve  ){
            int tar = 0 - *vb - *ve;
            cout << *vb << " " << *ve << " " << tar << endl;
            if ( tar < *vp ) { while ( vp != vb && *vp > tar ) --vp; }
            if ( tar > *vp ) { while ( vp != ve && *vp < tar ) ++vp; }
            cout << *vp << endl;
            if ( *vp == tar && vp != ve && vp != vb ) rv.push_back( vector<int>{*vb, *vp, *ve});
            if ( vp == vb && *vp == *( vb + 1 )) rv.push_back( vector<int> {*vb, *vp, *ve}); 
            if ( vp == ve && *vp == *( ve - 1 )) rv.push_back( vector<int> {*vb, *vp, *ve}); 

            if ( tar ) {
                while ( *vb == *(vb + 1) ) ++vb;
                ++vb;
                if ( (vp - vb) < 0 ) vp = vb;
            }
            else{
                while ( *ve == *(ve - 1) ) --ve;
                --ve;
                if ( (ve - vp ) < 0) vp = ve; 
            }
        }
        return rv;
    }
};

//正解：双指针法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rv;
        sort( nums.begin(), nums.end() );
        for ( auto i = 0; i < nums.size(); ++i ){
            if ( nums[i] > 0 ) break;

            if ( i > 0 && nums[ i ] == nums[ i - 1 ] ) continue;

            int left = i + 1, right = nums.size() - 1;
            while ( left < right ) {
                if ( nums[left] + nums[right] + nums[i] < 0 ) ++left;
                else if ( nums[left] + nums[right] + nums[i] > 0 ) --right;
                else {
                    rv.push_back ( vector<int> { nums[i], nums[left], nums[right] });
                    while ( left < right && nums[right] == nums[ right - 1 ]) --right;
                    while ( left < right && nums[left] == nums[ left + 1 ]) ++left;
                    ++left;
                    --right;
                }
            }
        }
        return rv;
    }
};