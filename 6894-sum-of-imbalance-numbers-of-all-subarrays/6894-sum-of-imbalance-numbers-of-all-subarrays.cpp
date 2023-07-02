class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            int cnt=0;

            // A set to store unique numbers along with their indices
            set<pair<int,int>> mp;

            for(int j=i ; j<n ; j++){
                mp.insert({nums[j],j});

                // Find the iterator pointing to the current number and index in the set
                auto it=mp.find({nums[j],j});

                if (it != mp.begin()) {
                    // If the current iterator is not pointing to the beginning of the set,
                    // find the iterators pointing to the previous and next elements in the set
                    auto L = prev(it);
                    auto R = next(it);
                    if (R != mp.end()) {
                        //If there is loss of an imbalance reduce 1
                        cnt -= abs(R->first - L->first) > 1;

                        //If next element and current element forms imbalance(abs_difference > 1)
                        //increment cnt by 1
                        cnt += abs(R->first - it->first) > 1;
                    }

                    //If prev element and current element forms imbalance(abs_difference > 1)
                    //increment cnt by 1
                    cnt += abs(L->first - it->first) > 1;
                } 

                else {
                    auto R = next(it);
                    if (R != mp.end()){
                        //If next element and current element forms imbalance(abs_difference > 1)
                        //increment cnt by 1
                        cnt += abs(R->first - it->first) > 1;
                    }
                }
                ans += cnt;
            }
        }
        return ans;
    }
};