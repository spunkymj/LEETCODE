class Solution {
public:
    int bitc(long long n){
        int ret=0;
        while(n){
            ret+=n&1;
            n=n>>1;
        }
        return ret;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size();
        int m = req_skills.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < m; i++) {
            mp[req_skills[i]] = i;
        }

        //person skills
        vector<int> ps(n);
        for (int i = 0; i < n; i++) {
            for (string skill : people[i]) {
                ps[i] |= 1 << mp[skill];
            }
        }
        vector<long long> dp(1 << m, (1LL << n) - 1);
        dp[0] = 0;
        for (int skillsMask = 1; skillsMask < (1 << m); skillsMask++) {
            for (int i = 0; i < n; i++) {
                int smallerSkillsMask = skillsMask & ~ps[i];
                if (smallerSkillsMask != skillsMask) {
                    long long peopleMask = dp[smallerSkillsMask] | (1LL << i);
                    if (bitc(peopleMask) < bitc(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
        }
        long long answerMask = dp[(1 << m) - 1];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((answerMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};