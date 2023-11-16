class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        for(int i=0 ; i<nums.size(); i++){
            nums[0][i]='0'+!(nums[i][i]-'0');
        }
        return nums[0];
    }
};