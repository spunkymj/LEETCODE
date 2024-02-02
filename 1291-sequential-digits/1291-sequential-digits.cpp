class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> d;
        for(int len=1 ; len<=9 ; len++){
            for(int start=1 ; start<=(10-len) ; start++){
                int curr=0;
                for(int j=start ; j<start+len ; j++){
                    curr=curr*10+j;
                }
                d.push_back(curr);
            }
        }
        auto itr=lower_bound(d.begin(),d.end(),low)-d.begin();
        vector<int> ans;
        for(itr ; itr<d.size() ; itr++){
            if(d[itr]>high){
                break;
            }
            ans.push_back(d[itr]);
        }
        return ans;
    }
};