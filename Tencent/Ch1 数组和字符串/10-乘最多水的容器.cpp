class Solution {
public:
    int maxArea(vector<int>& height) {
        using Pair = pair< int, int >;
        vector <Pair> vp;
        int cnt = 0, ans = 0;
        vp.push_back( Pair( 0, height[0] ) ); ++cnt;
        for ( auto i = 1; i < height.size(); ++i ){
            for ( auto j = 0; j < cnt; ++j ) 
                ans = max( ans, min( vp[j].second, height[i] ) * ( i - vp[j].first  ));
            if ( vp[ cnt - 1 ].second < height[i] ) vp.push_back( Pair( i, height[i] )), ++cnt;
        }
        return ans;
    }
};
// O ( n^ 1.5 )

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while ( left < right ){
            ans = max ( ans, ( right - left ) * min( height[left], height[right] ) );
            if ( height[left] < height[right] ) ++left;
            else --right;
        }
        return ans;
    }
};
// O ( n )