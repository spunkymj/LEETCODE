class Solution {
public:
    void gen(vector<string> &v,int idx,int n,string &s){
        if(idx==n){
            v.push_back(s);
            return;
        }
        s+='0';
        gen(v,idx+1,n,s);
        s.pop_back();
        s+='1';
        gen(v,idx+1,n,s);
        s.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> v;
        int n=nums.size();
        string s="";
        gen(v,0,n,s);
        for(auto c : v){
            bool chk=true;
            for(auto e : nums){
                if(c==e){
                    chk=false;
                    break;
                }
            }
            if(chk){
                return c;
            }
        }
        return nums[0];
    }
};