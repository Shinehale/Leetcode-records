class Solution {
public:
    int climbStairs(int n) {
        vector<int> vint;
        vint.insert(vint.begin(),{0,1,2});
        for ( int i = 3 ; i < n + 1 ; ++i ) {
            int newValue = vint[ i - 1 ] + vint[ i - 2 ];
            vint.push_back( newValue );
        }
        return vint[n];
    }
};
// O(n)