class Solution {
public:
    int maxProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto e : nums){
            mp[e]++;
        }
        int maxi=-1;
        for(int k=1000 ; k>=1 ; k--){
            if(mp[k]>0){
                if(mp[k]>1){
                    return (k-1)*max(maxi,(k-1));
                }
                else{
                    if(maxi==-1){
                        maxi=k-1;
                    }
                    else{
                        return (k-1)*maxi;
                    }
                }
            }
        }
        return 0;
    }
};