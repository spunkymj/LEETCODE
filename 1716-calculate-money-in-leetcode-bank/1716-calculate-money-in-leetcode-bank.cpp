class Solution {
public:
    int totalMoney(int n) {
        int gp_len=n/7;
        int ans=0;
        for(int i=1 ; i<=7 ; i++){
            if(i<=(n%7)){
                ans+=(((gp_len+1))*(2*i+(gp_len)))/2;
            }
            else{
                ans+=(((gp_len))*(2*i+(gp_len-1)))/2;
            }
        }
        return ans;
    }
};