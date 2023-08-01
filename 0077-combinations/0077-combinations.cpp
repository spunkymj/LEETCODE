class Solution {
public:
    void solve(int idx , int n , int k ,vector<int> &temp, vector<vector<int>> &v){
        if(idx==n+1 || temp.size()==k){
            if(temp.size()==k){
                v.push_back(temp);
            }
            return;
        }
        temp.push_back(idx);
        solve(idx+1,n,k,temp,v);
        temp.pop_back();
        solve(idx+1,n,k,temp,v);
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> temp;
        solve(1,n,k,temp,v);
        return v;
    }
};