class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for ( auto each : s ){
            if ( each == '[' ) S.push( each );
            if ( each == '{' ) S.push( each );
            if ( each == '(' ) S.push( each );
            if ( each == ')' ) {
                if ( S.empty() ) return false;
                if ( S.top() != '(' ) return false;
                else S.pop();
            }
            if ( each == ']' ) {
                if ( S.empty() ) return false;
                if ( S.top() != '[' ) return false;
                else S.pop();
            }
            if ( each == '}' ) {
                if ( S.empty() ) return false;
                if ( S.top() != '{' ) return false;
                else S.pop();
            }
        }
        if ( !S.empty() ) return false;
        else return true;
    }
};