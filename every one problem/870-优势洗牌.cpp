class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        using Pair = pair< int, int >;
        vector<Pair> target; int cnt = 0;
        for ( auto each : nums2 ) {
            ++cnt;
            target.push_back( Pair( each, cnt ));
        }
        sort(target.begin(), target.end(), [](const Pair& lpv, const Pair& rpv) -> bool { 
            return lpv.first < rpv.first;
        } );
        // for_each( target.begin(), target.end(),[]( const Pair p ) { cout << p.first << " " << p.second << endl;});
        sort( nums1.begin(), nums1.end() );
        vector<int> ans( nums2.size() );
        cnt = 0;
        stack<int> stk;
        for ( int i = 0; i < nums1.size(); ++i ){
            if ( nums1[i] > target[cnt].first ) {
                ans[ target[cnt].second - 1 ] = nums1[i];
                ++cnt;
            }
            else stk.push( nums1[i] );

        }
        for ( int i = cnt; i < nums1.size(); ++i ) ans[ target[i].second - 1 ] = stk.top(), stk.pop(); 
        return ans;
    }
};
