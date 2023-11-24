class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int idx=n-2;
        int ans=0;
        int cnt=0;
        while(idx>=0){
            ans+=piles[idx];
            cnt++;
            if(cnt==n/3){
                break;
            }
            idx-=2;
        }
        return ans;
    }
};