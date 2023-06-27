class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n=nums1.size() ;
        int m=nums2.size() ;
        int i=0 ; 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        while(k-- && i<n){
            if(pq.empty() || (pq.top().first>nums1[i]+nums2[0])){
                pq.push({nums1[i]+nums2[0],{i,0}});
                i++;
            }
            auto curr=pq.top();
            int ii=curr.second.first;
            int jj=curr.second.second+1;
            if(jj<m){
                pq.push({nums1[ii]+nums2[jj],{ii,jj}});
            }
            else{
                if(i<n){
                    pq.push({nums1[i]+nums2[0],{i,0}});
                    i++;
                }
            }
         ans.push_back({nums1[pq.top().second.first],nums2[pq.top().second.second]});
                pq.pop();
        }
        k++;
        while(k--){
            if(pq.empty()){
                break;
            }
            auto curr=pq.top();
            int ii=curr.second.first;
            int jj=curr.second.second+1;
            if(jj<m){
                pq.push({nums1[ii]+nums2[jj],{ii,jj}});
            }
            else{
                if(i<n){
                    pq.push({nums1[i]+nums2[0],{i,0}});
                    i++;
                }
            }
        ans.push_back({nums1[pq.top().second.first],nums2[pq.top().second.second]});
                pq.pop();
        }
        return ans;
    }
};