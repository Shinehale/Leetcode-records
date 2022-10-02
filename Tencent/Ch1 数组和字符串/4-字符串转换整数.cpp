class Solution {
public:
    int myAtoi(string s) {
        using LL = long long;
        string str1 = "", str2 = "";
        bool flag = false;
        const LL maxValue = ( 1 << 31 ) - 1;
        bool check = false;
        for ( auto i = 0; i < s.size(); ++i ){
            if ( s[i] == ' ' && !check ) continue;
            else {
                str1 += s[i];
                check = true;
            }
        }
        check = false;
        for ( auto i = 0; i < str1.size(); ++i ){
            if ( s[i] >= '0' && s[i] <= '9' ) check = true;
            if ( check && ( s[i] > '9' || s[i] < '0' ) ) break; 
            str2 += str1[i];
        }
        LL ansVal = 0; 
        int pos = 0;
        if ( str2[0] == '-' ) {flag = true; pos = 1;}
        else if (str2[0] == '+' ) pos = 1;
        for ( auto i = pos ; i < str2.size(); ++i ){
            if ( str2[i] > '9' || str2[i] < '0' ) break;
            ansVal = ansVal * 10 + (str2[i] - '0');
            if ( ansVal > maxValue + 1 ) {
                ansVal = maxValue + 1;
                break;
            }
        }
        if ( !flag ) {
            if ( ansVal >= maxValue ) return maxValue;
            else return ansVal;
        }
        else {
            if ( ansVal >= maxValue + 1 ) return (1<<31);
            else return -ansVal;
        }
    }
};
// O(n)