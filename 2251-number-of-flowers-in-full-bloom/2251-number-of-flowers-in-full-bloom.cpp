class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(),flowers.end());
        int idx=0;
        int fs=flowers.size();
        int ps=people.size();
        vector<int> trav(ps,0);
        iota(trav.begin(),trav.end(),0);
        sort(trav.begin(),trav.end(),[&](int a,int b){
            return people[a]<people[b];
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> ans(ps,0);
        for(int i=0 ; i<ps; i++){
            while(idx<fs && flowers[idx][0]<=people[trav[i]]){
                pq.push(flowers[idx][1]);
                idx++;
            }
            while(!pq.empty() && pq.top()<people[trav[i]]){
                pq.pop();
            }
            ans[trav[i]]=pq.size();
        }
        return ans;
    }
};