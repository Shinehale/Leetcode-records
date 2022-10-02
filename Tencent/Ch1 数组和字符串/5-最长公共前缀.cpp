class Solution {
public:
    bool check( vector<string>& strs , int len ){
        string tar;
        for ( auto i = 0; i < len; ++i ) tar += strs[0][i];
        for ( auto i = 0; i < strs.size(); ++i ) {
            for ( auto j = 0; j < len ; ++j ) 
            if ( strs[i][j] != tar[ j ]) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string::size_type minLen = 201;
        for ( auto each : strs ) minLen = min( minLen, each.size() );
        int ansL = 0, ansR = minLen , ansLen ;
        while ( ansL <= ansR ){
            int mid = ( ansL + ansR ) >> 1;
            if ( check ( strs, mid ) ) ansLen = mid, ansL = mid + 1;
            else ansR = mid - 1  ;
        }
        string ans;
        for ( auto i = 0; i < ansLen; ++i ) ans += strs[0][i];
        return ans;
    }
    
};
// O(log(minLen) * minLen * n)
// n = strs.size() 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];

        for(int i = 1; i < strs.size(); i++){
            string tmp = "";
            int minlen = pre.length() > strs[i].length() ? strs[i].length() : pre.length();
            for(int j = 0; j < minlen; j++){
                if(pre[j] == strs[i][j]){
                    tmp += pre[j];
                }else{
                    break;
                }
            }
            pre = tmp;
        }
        return pre;
    }
};
// O (n * minLen) 