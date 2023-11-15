class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        map<int,int> mp;
        for(auto e : arr){
            mp[e]++;
        }
        int prev=1;
        bool first=0;
        for(auto m : mp){
            int n=m.first;
            int f=m.second;
            if(first==0){
                first=1;
                prev=min(f,n);
                continue;
            }
            prev+=min(f,n-prev);
        }
        return prev;
    }
};