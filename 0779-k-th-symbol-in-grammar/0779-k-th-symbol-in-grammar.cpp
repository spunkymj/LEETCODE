class Solution {
public:
    int kthGrammar(int n, int k) {
        int curr=k-1;
        int ans=0;
        while(curr){
            if(curr&1){
                ans++;
            }
            curr=curr>>1;
        }
        return ans&1;
    }
};