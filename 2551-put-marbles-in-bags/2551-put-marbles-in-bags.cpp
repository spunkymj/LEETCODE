class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1 || k==weights.size()){
            return 0;
        }
        vector<long long> div;
        for(int i=0 ; i<weights.size()-1 ; i++){
            div.push_back(weights[i]+weights[i+1]);
        }
        sort(div.begin(),div.end());
        long long ans=0;
        int n=div.size();
        for(int i=0 ; i<k-1 ; i++){
            ans+=div[n-1-i]-div[i];
        }
        return ans;
    }
};