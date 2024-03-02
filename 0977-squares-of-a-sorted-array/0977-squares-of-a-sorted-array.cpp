class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        int n=nums.size();
        for(int i=0 ; i<n  ; i++){
            if(nums[i]>=0){
                v1.push_back(nums[i]*nums[i]);
            }
            else{
                v2.push_back(nums[i]*nums[i]);
            }
        }
        vector<int> ans;
        int i=0;
        int j=v2.size()-1;
        while(i<v1.size() && j>=0){
            if(v1[i]>v2[j]){
                ans.push_back(v2[j]);
                j--;
            }
            else{
                ans.push_back(v1[i]);
                i++;
            }
        }
        while(j>=0){
            ans.push_back(v2[j]);
            j--;
        }
        while(i<v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        return ans;
    }
};