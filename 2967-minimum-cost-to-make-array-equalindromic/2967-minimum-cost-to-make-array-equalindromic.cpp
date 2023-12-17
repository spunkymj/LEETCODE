class Solution {
public:
    bool chk(int n){
        string str=to_string(n);
        for(int i=0 ; i<str.size()/2 ; i++){
            if(str[i]!=str[str.size()-1-i]){
                return false;
            }
        }
        return true;
    }

    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        int case1=nums[n/2];
        while(!chk(case1)){
            case1++;
        }
        int case2=nums[n/2];
        while(!chk(case2)){
            case2--;
        }

        //case 1
        long long cost1=0;
        for(int i=0 ; i<n ; i++){
            cost1+=abs(nums[i]-case1);
        }

        //case 2
        long long cost2=0;
        for(int i=0 ; i<n ; i++){
            cost2+=abs(nums[i]-case2);
        }
        
        return min(cost1,cost2);
    }
};