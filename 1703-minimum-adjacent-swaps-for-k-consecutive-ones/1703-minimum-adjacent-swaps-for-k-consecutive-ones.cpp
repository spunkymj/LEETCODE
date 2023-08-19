class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> pos;
        int n=nums.size();
        pos.push_back(0);
        for(int i=0 ; i<n ; i++){
            if(nums[i]){
                pos.push_back(i);
            }
        }
        n=pos.size();
        vector<long long> prefix(n,0);
        for(int i=1 ; i<n ; i++){
            prefix[i]+=prefix[i-1]+pos[i];
        }

        long long ans=1e18;
        for(int l=1 ,r=k ; r<n ; l++,r++){
            long long mid=l+((r-l)/2);
            long long left=prefix[mid-1]-prefix[l-1];
            long long right=prefix[r]-prefix[mid];
            long long radius=(k-1)/2;
            long long subtract=radius*(radius+1);
            if(k%2==0){
                left+=pos[mid];
                subtract+=radius+1;
            }
            ans=min(ans,right-left-subtract);
        }
        return (int)ans;

    }
};