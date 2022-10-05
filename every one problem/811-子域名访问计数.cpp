class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map <string , int> mp;
        for ( auto each : cpdomains ){
            string str, totalStr; 
            vector< string > vstr;
            bool flag = true , check = false;
            int value = 0;
            for ( auto i = 0; i < each.size(); ++i ) {
                if ( each[i] != ' ' && flag ) str += each[i];
                else if ( flag ){
                    flag = false;
                    check = true;
                    value = exchange( str );
                    str = "";
                    continue;
                }else if ( each[i] == '.' && check ) {
                    vstr.push_back( str );
                    str = "";
                }else str += each[i];
            }
            vstr.push_back(str);
            vector<string> vecStr;
            totalStr = vstr[ vstr.size() - 1 ];
            vecStr.push_back( totalStr );
            for ( int i = vstr.size() - 2; i >= 0 ;--i ) totalStr = vstr[i] + "." +totalStr, vecStr.push_back( totalStr );
            for ( auto eachStr : vecStr )  mp[eachStr] += value;
        }
        vector< string > ans;
        map< string, int >::iterator mpbe = mp.begin(), mpen = mp.end();
        while ( mpbe != mpen ) {
            ans.push_back( exchange( mpbe -> second ) + " " + mpbe->first );
            ++mpbe;
        }
        return ans;
    }
    int exchange( string str ){
        int rv = 0;
        for ( auto i = 0; i < str.size(); ++i ) rv = rv * 10 + str[i] - '0';
        return rv;
    }
    string exchange( int tar ){
        string s; stack <int> S;
        while ( tar ) {
            S.push( tar % 10 );
            tar /= 10;
        }
        while ( !S.empty() ) {
            s += S.top() + '0';
            S.pop();
        }
        return s;
    }
};
