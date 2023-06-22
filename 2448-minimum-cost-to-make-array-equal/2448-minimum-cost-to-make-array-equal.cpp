class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long totalcost=0;
        long long sum=0;
        long long mini=1e18;
        vector<pair<long long , long long>> v;
        for(int i=0 ; i<nums.size() ; i++){
            totalcost+=((long long)nums[i]*(long long)cost[i]);
            sum+=(long long)cost[i];
            v.push_back({(long long)nums[i],(long long)cost[i]});
        }
        sort(v.begin(),v.end());
        long long prev=0;
        long long ts=totalcost;
        long long c=sum;

        //   for i=k : C1(xk-x1)+C2(xk-x2)+...+Ck(xk-xk)+Ck+1(xk+1-xk)+....Cn(xn-xk)
        //   or it could be written as
        //   total cost = (-C1x1-C2x2....+Ckxk+....Cnxn)-xk(-C1-C2...+Ck+ ...+Cn)
        //   Observe pattern for consecutive i's.
        //   i=0 total cost=  (+C1x1+C2x2.....Cnxn)-x1(+C1+C2....+Cn)
        //   i=1 total cost=  (-C1x1+C2x2.....Cnxn)-x2(-C1+C2....+Cn)
        //   i=2 total cost=  (-C1x1-C2x2+C3x3.....Cnxn)-x3(-C1-C2+C3....+Cn)
        for(int i=0 ; i<v.size() ; i++){
            int num=v[i].first;
            totalcost=ts-num*(sum);
            if(totalcost<mini){
                mini=totalcost;
            }
            sum-=2*v[i].second;
            ts-=2*num*v[i].second;
        }
        return mini;
    }
};