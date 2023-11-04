class Solution {
public:
    vector<int> decode(vector<int>& a) {
        int n=a.size()+1;
        for(int i=1 ; i<n-1 ; i++){
            a[i]^=a[i-1];
        }
 
        vector<int> bit1(30,0);
        vector<int> bit2(30,0);
        for(auto e : a){
            for(int j=0 ; j<30 ; j++){
                bit1[j]+=((e>>j)&1);
            }
        }
        for(int i=1; i<=n ;i++){
            for(int j=0 ; j<30 ; j++){
                bit2[j]+=((i>>j)&1);
            }
        }
        int x=0;
        for(int i=0 ; i<30 ; i++){
            if(bit1[i]!=bit2[i]){
                x+=(1<<i);
            }
        }
        vector<int> ans;
        ans.push_back(x);
        for(int i=0 ; i<n-1 ; i++){
            ans.push_back(a[i]^x);
        }   

        return ans;
    }
};