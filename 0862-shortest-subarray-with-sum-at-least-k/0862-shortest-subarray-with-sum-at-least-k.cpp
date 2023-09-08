class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        
        //prefix array 
        vector<long long> p(n+1,0);
        for(int i=0 ; i<n ; i++){
            p[i+1]+=p[i]+nums[i];
        }

        
        deque<int> q;
        int ans=1e9;
        q.push_back(0);
        for(int i=1 ; i<=n ; i++){
            //Calculating minimum possible ans
            while(!q.empty() && p[i]-p[q.front()]>=k){
                ans=min(ans,i-q.front());
                q.pop_front();
            }
            //removing unnecessary elements
            while(!q.empty() && p[i]<p[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans==1e9 ? -1 : ans;
    }
};