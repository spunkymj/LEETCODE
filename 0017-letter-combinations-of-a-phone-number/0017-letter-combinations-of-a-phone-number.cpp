class Solution {
public:
    void solve(vector<string> &ans,string digits,int idx,vector<string> &ph,string &curr){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        for(auto ch : ph[digits[idx]-'2']){
            curr+=ch;
            solve(ans,digits,idx+1,ph,curr);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string> ph={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr="";
        solve(ans,digits,0,ph,curr);
        return ans;
    }
};