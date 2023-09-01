class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1 ; i<n+1 ; i++){
            int cnt=0;
            for(int j=0 ; j<30 ; j++){
                if((1<<j)&i){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};