class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=INT_MIN,num2=INT_MIN;
        int count1=0,count2=0;
        for(auto e : nums){
            if(num1==e){
                count1++;
            }
            else if(num2==e){
                count2++;
            }
            else if(count1==0){
                num1=e;
                count1=1;
            }
            else if(count2==0){
                num2=e;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        int k=nums.size()/3;
        vector<int> ans;
        count1=0,count2=0;
        for(auto e : nums){
            if(e==num1){
                count1++;
            }
            if(e==num2){
                count2++;
            }
            if(count1>k){
                ans.push_back(e);
                count1=INT_MIN;
            }
            if(count2>k){
                ans.push_back(e);
                count2=INT_MIN;
            }
        }
        return ans;

    }
};