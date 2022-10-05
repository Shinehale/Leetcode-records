class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;int cnt = 0;string str;
        for ( auto each : s ) 
            if ( each == ' ' ) {
                ++cnt;
                vs.push_back( str );
                str = "";
            }else str += each;
        vs.push_back( str );
        for ( auto & each : vs ) reverse( each );
        string ans;
        for ( int i = 0; i < vs.size() - 1; ++i ) ans += vs[i] + ' ';
        ans += vs[ vs.size() - 1 ];
        return ans;
    }
    void reverse( string& s ){
        char tmp;
        int Left = 0, Right = s.size() - 1;
        while ( Left < Right ) {
            tmp = s[Left];
            s[Left] = s[Right];
            s[Right] = tmp;
            ++Left ;
            --Right;
        }
    }
};