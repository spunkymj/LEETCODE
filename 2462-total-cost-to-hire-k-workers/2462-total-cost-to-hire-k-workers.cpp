class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        if(2*candidates>=costs.size()){
            sort(costs.begin(),costs.end());
            return accumulate(costs.begin(),costs.begin()+k,0);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i,j;
        for(i=0 ; i<candidates ; i++){
            pq.push({costs[i],i});
        }
        for( j=costs.size()-1 ; (j>=i) && (j>=costs.size()-candidates) ; j--){
            pq.push({costs[j],j});
        }
        long long ans=0;
        for(int kk=0 ; kk<k ; kk++){
            ans+=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            if(idx<i && i<=j){
                pq.push({costs[i],i});
                i++;
            }
            else if(idx>j && j>=i){
                pq.push({costs[j],j});
                j--;
            }
        }
        return ans;
    }
};