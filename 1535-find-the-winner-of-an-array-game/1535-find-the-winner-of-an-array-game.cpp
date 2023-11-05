class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }
        
        int curr = arr[0];
        int winstreak = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            int opponent = arr[i];
            
            if (curr > opponent) {
                winstreak++;
            } else {
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxi) {
                return curr;
            }
        }
        
        return -1;
    }
};