class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int curr=0;
        for(int i=0 ; i<n ; i++){
            if(i%7==0){
                curr++;
                ans+=curr;
            }
            else{
                ans+=curr+(i%7);
            }
        }
        return ans;
    }
};