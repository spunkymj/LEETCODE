class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int idx=0;
        vector<string> ans;
        for(int i=1 ; i <= n; i++){
            if(idx<target.size() && target[idx]==i){
                ans.push_back("Push");
                idx++;
            }
            else if (idx<target.size() && target[idx]!=i){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};