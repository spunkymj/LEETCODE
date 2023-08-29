class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> prefixN(n+2,0);
        vector<int> suffixY(n+2,0);
        for(int i=1 ; i<=n ; i++){
            prefixN[i]+=prefixN[i-1]+(customers[i-1]=='N');
            suffixY[n-i+1]+=suffixY[n-i+2]+(customers[n-i]=='Y');
        }

        int mini=1e9;
        int ans=0;
        for(int i=1 ; i<=n+1 ; i++){
            int current_penalty=prefixN[i-1]+suffixY[i];
            if(current_penalty<mini){
                mini=current_penalty;
                ans=i-1;
            }
        }
        return ans;
    }
};