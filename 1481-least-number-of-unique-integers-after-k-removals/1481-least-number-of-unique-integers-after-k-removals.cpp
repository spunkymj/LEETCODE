class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto e : arr){
            mp[e]++;
        }
        vector<int> v;
        for(auto [x,y] : mp ){
            v.push_back(y);
        } 
        sort(v.begin(),v.end());
        for(int i=0 ; i<v.size() ; i++){
            if(v[i]<=k){
                k-=v[i];
            }
            else{
                return (v.size()-i);
            }
        }
        return 0;
    }
};