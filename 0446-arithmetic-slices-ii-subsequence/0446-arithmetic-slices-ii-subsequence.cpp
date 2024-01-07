class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        vector<map<long long, int>> dp(n); 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff=(long long) nums[i] - nums[j];
                int curr=dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff]+=curr + 1;
                ans+=curr;
            }
        }
        return ans;
    }
};