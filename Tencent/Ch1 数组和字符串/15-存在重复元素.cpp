class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for ( auto each : nums ) 
        if ( mp[ each ] == 1 ) return true;
        else mp[ each ] = 1;
        return false;
    }
};
// O (n)