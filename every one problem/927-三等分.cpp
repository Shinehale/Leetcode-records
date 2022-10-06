class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int total = 0;
        for ( auto i = 0; i < arr.size(); ++i ) if ( arr[i] == 1 ) ++total;
        if ( total % 3 ) return vector<int>{ -1, -1 };
        if ( total == 0 ) return vector<int> {0, (int)arr.size() - 1};
        int first = 0, second = 0, third = 0, partial = total / 3, cur = 0;
        for ( auto i = 0; i < arr.size(); ++i ){
            if ( arr[i] == 1 ) {
                if ( cur == 0 ) first = i;
                if ( cur == partial ) second = i;
                if ( cur == 2 * partial ) third = i;
                ++cur;
            }
        }
        int len = arr.size() - third;
        if ( first + len <= second && second + len <= third ){
            int pos = 0;
            while ( third + pos < arr.size() ){
                if ( arr[ first + pos ] != arr[ second + pos ] || arr[ first + pos ] != arr[ third + pos ]) 
                    return vector<int>{-1, -1};
                ++pos;
            }
            return vector<int> { first + len - 1, second + len };
        }
        return vector<int> { -1, -1 };
    }
};
// O (n)