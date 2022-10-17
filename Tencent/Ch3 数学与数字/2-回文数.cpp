class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ) return false;
        vector<int> ivec;
        while ( x ) ivec.push_back( x % 10 ), x = x / 10;
        int head = 0, tail = ivec.size() - 1;
        while ( head < tail ){
            if ( ivec[ head ] != ivec[ tail ]) return false;
            ++head;
            --tail;
        }
        return true;

    }
};