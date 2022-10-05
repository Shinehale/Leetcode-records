class Solution {
public:
    void reverseString(vector<char>& s) {
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
// O (n) 空间 O(1)