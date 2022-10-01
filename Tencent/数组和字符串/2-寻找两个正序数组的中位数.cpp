class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        bool flag = (nums1.size() + nums2.size()) % 2;
        int target = (nums1.size() + nums2.size()) / 2 ;
        int i = 0, j = 0;
        while ( i < nums1.size()  && j < nums2.size() ){
            if ( nums1[i] > nums2[j] ){
                merge.push_back(nums2[j]);
                ++j;
            }
            else {
                merge.push_back(nums1[i]);
                ++i;
            }
        }
        while ( i < nums1.size() ){
            merge.push_back(nums1[i]);
            ++i;
        }
        while ( j < nums2.size() ){
            merge.push_back(nums2[j]);
            ++j;
        }
        if ( flag ) return merge[target];
        else return ( merge[target-1] + merge[target] ) / 2.0;
    }
};
// O (n+m)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        int left = (n1 + n2 + 1) / 2;
        int right = (n1 + n2 + 2) / 2;
        return ( getKth( nums1, 0, n1 - 1, nums2, 0, n2 - 1, left ) 
            + getKth( nums1, 0, n1 - 1, nums2, 0, n2 - 1, right) ) / 2;   // 统一奇数与偶数
    }
    double getKth( vector<int>& nums1, const int& start1,const int& end1,
                    vector<int>& nums2,const int& start2,const int& end2, const int& k ) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if( len1 > len2 )
            return getKth( nums2, start2, end2, nums1, start1, end1, k );
        if( len1 == 0 )
            return nums2[start2 + k - 1];
        if( k == 1 )
            return min( nums1[start1], nums2[start2] );
        int i = start1 + min( len1, k / 2 ) - 1;
        int j = start2 + min( len2, k / 2 ) - 1; 
        if( nums1[i] > nums2[j] )
            return getKth( nums1, start1, end1, nums2, j + 1, end2, k - ( j - start2 + 1 ) );
        else
            return getKth( nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1 ) );
    }
};
// O ( log ( n + m ) )
