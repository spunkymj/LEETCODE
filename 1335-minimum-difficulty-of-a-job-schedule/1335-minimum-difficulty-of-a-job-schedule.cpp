int dp[301][11];
class Solution {
public:
    
    int helper(vector<int>& arr, int i, int n, int k)
    {   
        if(i == n && k == 0)
            return 0;
        
        if(k <= 0)
            return INT_MAX;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int maxi = 0;
        int mini = INT_MAX;
        
        for(int j = i; j < n; j++)
        {
            maxi = max(maxi, arr[j]);
            
            int temp = helper(arr, j + 1, n, k - 1);
            
            if(temp != INT_MAX)
            {
                mini = min(mini, maxi + temp);
            }
        }
        return dp[i][k] = mini;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        memset(dp, -1, sizeof(dp));
        int mini = helper(jobDifficulty, 0, n, d);
        if(mini == INT_MAX)
            return -1;
        
        return mini;
    }
};