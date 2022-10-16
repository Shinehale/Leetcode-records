class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0, pos2 = 0;
        vector<int> ans;
        while ( pos1 < m && pos2 < n ){
            if ( nums1[pos1] < nums2[pos2] ) ans.push_back( nums1[pos1] ), ++pos1;
            else ans.push_back( nums2[pos2] ), ++pos2; 
        }
        while ( pos1 < m ) ans.push_back( nums1[pos1] ), ++pos1;
        while ( pos2 < n ) ans.push_back( nums2[pos2] ), ++pos2; 
        for ( auto i = 0; i < nums1.size(); ++i ) nums1[i] = ans[i];
    }
};