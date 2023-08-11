class Solution {
public:
    int change(int tamount, vector<int>& coins) {
        int n=coins.size();
        vector<int> prev(tamount+1,0); 
        prev[0]=1;

        for(int i=0 ; i<n ; i++){
            for(int amount=0 ; amount<=tamount ; amount++){
                if(coins[i]<=amount){
                    prev[amount]+=prev[amount-coins[i]];
                }
            }
        }
        return prev[tamount];
    }
};