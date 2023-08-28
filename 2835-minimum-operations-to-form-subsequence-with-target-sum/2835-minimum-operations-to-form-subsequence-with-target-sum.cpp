class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> c(32,0);
        long long sum=0;
        for(int e : nums){
            sum+=e;
            c[log2(e)]++;
        }
        if(sum<target){
            return -1;
        }
        
        int op=0;
        int idx=0;
        while(idx<31){
            if((1<<idx)&target){
                if(c[idx]>0){
                    c[idx]--;
                }
                else{
                    while(idx<31 && c[idx]==0){
                        op++;
                        idx++;
                    }
                    c[idx]--;
                    continue;
                }
            }
            c[idx+1]+=c[idx]/2;
            idx++;
        }

        return op;
    }
};