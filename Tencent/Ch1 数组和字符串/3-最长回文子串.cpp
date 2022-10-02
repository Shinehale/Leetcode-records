class Solution {
public:
	std::string longestPalindrome(std::string s) {
        int n=s.size();
        if(n<2) return s;
        int maxx=0, start=0;
        //以当前字符为中心向两边扩散查找
        for(int i=0; i<n; ){
            if(n-1 < maxx/2) break;
            int left=i, right=i;
            while(right<n-1 && s[right]==s[right+1]){
                ++right;
            }
            i=right+1;
            while(right<n-1 && left>0 && s[right+1]==s[left-1]){
                right++;
                left--;
            }
            if(right-left+1 > maxx){
                start=left;
                maxx = right-left+1;
            }
        }
        return s.substr(start,maxx);
	}
};
