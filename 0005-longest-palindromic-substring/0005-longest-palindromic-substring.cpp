class Solution {
public:
    string longestPalindrome(string s){
        int n=s.size();
        int max_len=1;
        int start=0;
        for (int i=0 ; i<n ; i++ ){
            if ((n-i)<(max_len/2)){
                break;
            }
            int l=i;
            int h=i;
            while ( (h<n-1) && (s[h]==s[h+1])){
                h++;
            }
            i=h;
            while((l>=0) && ( h <=n-1 ) && s[l]==s[h]){
                l--;
                h++;
            }
            int len=h-l-1;
            if (len>max_len){
                max_len=len;
                start=l+1;
            }
        }
        return s.substr(start,max_len);
    }
};