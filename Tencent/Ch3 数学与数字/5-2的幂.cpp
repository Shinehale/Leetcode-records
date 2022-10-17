class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n <= 0 ) return false;
        const double eps = 1e-10;
        double val = log( n );
        double times = val / log( 2 );
        int time = times;
        if ( abs( times - time ) < eps ) return true;
        return false;
    }
};