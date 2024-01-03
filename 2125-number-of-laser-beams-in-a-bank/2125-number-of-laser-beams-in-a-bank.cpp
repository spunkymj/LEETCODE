class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int> cnt(n,0);
        for(int i=0 ; i<n ; i++){
            int curr=0;
            for(auto ch : bank[i]){
                curr+=(ch=='1');
            }
            cnt[i]=curr;
        }
        int ans=0;
        int prev=0;
        for(int i=0 ; i<n ; i++){
            ans+=prev*cnt[i];
            if(cnt[i]>0){
                prev=cnt[i];
            }
        }
        return ans;
    }
};