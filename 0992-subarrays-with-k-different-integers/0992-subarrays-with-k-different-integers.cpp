class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> d(nums.size() + 1, 0);
        int cnt = 0;
        int left = 0;
        int right = 0;
        int curr = 0;

        while (right < nums.size()) {
            if (++d[nums[right++]] == 1) {
                k--;
            }

            if (k < 0) {
                --d[nums[left++]];
                k++;
                curr = 0;
            }

            if (k == 0) {
                while (d[nums[left]] > 1) {
                    --d[nums[left++]];
                    curr++;
                }
                cnt += (curr + 1);
            }
        }
        return cnt;
    }
};