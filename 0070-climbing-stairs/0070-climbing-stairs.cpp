class Solution {
public:
    int climbStairs(int n) {
        int s1=1;
        int s2=1;
        int ans=1;
        for(int i=2 ; i<=n ; i++){
            ans=s1+s2;
            s1=s2;
            s2=ans;
        }
        return ans;
    }
};