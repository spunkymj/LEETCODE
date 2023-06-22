#define ll long long
class Solution {
public:
    //dynamic programming 
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; i++){
            v.push_back({nums[i],cost[i]});
        }    
        sort(v.begin(),v.end());

        //left cost : making elements in left equal to right
        vector<ll> cost_l(n,0);
        ll curr=0;
        for(int i=0 ; i<n-1 ; i++){
            curr+=(ll)v[i].second;
            cost_l[i+1]=cost_l[i]+curr*(ll)(v[i+1].first-v[i].first);
        }

        //right cost
        vector<ll> cost_r(n,0);
        curr=0;
        for(int i=n-1 ;i>0 ; i--){
            curr+=(ll)v[i].second;
            cost_r[i-1]=cost_r[i]+curr*(ll)(v[i].first-v[i-1].first);
        }

        ll ans=cost_l[0]+cost_r[0];
        for(int i=1 ; i<n ; i++){
            ans=min(ans,cost_l[i]+cost_r[i]);
        }
        return ans;
    }
};