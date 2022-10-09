class Solution {
public:
    int scoreOfParentheses(string s) {
        const int N = 50;
        int dep = 0, curVal = 0;
        vector<int> depVal( N );
        for ( auto i = 0; i < s.size(); ++i ){
            if ( s[i] == '(' ) ++dep;
            else {
                if ( s[ i - 1 ] =='(' ) {
                    --dep;
                    depVal[dep] += 1;
                }else{
                    depVal[dep - 1] += depVal[ dep ] * 2;
                    depVal[ dep ] = 0;
                    --dep;
                }
            }
        }
        return depVal[0];
    }
};
// O(n)