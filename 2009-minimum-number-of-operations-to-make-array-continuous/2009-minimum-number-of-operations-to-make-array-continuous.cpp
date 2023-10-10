#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

class Solution {
public:
    int minOperations(vector<int>& nums) {
        pbds st;
        unordered_map<int,int> mp;
        int sz=nums.size();
        for(auto &e : nums){
            st.insert(e);
            mp[e]=1;
        }
        int ans=1e9;
        for(auto m : mp){
            int curr=m.first;
            auto val1=st.order_of_key(curr+sz);
            auto val2=st.order_of_key(curr);
            int op=(sz-val1)+val2;
            ans=min(ans,op);
        }
        return ans;
    }
};