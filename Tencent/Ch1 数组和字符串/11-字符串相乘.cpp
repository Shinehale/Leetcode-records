class Solution {
public:
    string multiply(string num1, string num2) {
        if ( num1 == "0" || num2 == "0" ) return "0";
        vector<int> v(num1.size() + num2.size() + 1);
        string s1 = "", s2 = "";
        for ( int i = num1.size() - 1; i >= 0; --i ) s1 += num1[i];
        for ( int i = num2.size() - 1; i >= 0; --i ) s2 += num2[i];

        for ( auto i = 0; i < s1.size(); ++i )
            for ( auto j = 0; j < s2.size(); ++j )
                v[ i + j ] += ( s1[i] - '0' ) * ( s2[ j ] - '0');
        for ( auto i = 0 ; i < v.size() - 1; ++i )
            v[i + 1] += v[ i ] / 10, v[ i ] = v[ i ] % 10;
        bool flag = true;
        string ans;
        for ( int i = v.size() - 1; i >= 0 ; --i ) {
            if ( v[i] != 0 ) flag = false;
            if ( v[i] == 0 && flag ) continue;
            ans += '0' + v[i];
        }
        return ans;
    }
};
// O (n*m) n是num1长度，m是num2长度