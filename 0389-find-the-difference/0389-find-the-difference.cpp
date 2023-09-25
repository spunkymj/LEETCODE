class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0;
        int sum2=0;
        for(auto e : t){
            sum1+=(e-'a');
        }
        for(auto e : s){
            sum2+=(e-'a');
        }
        return ('a'+(sum1-sum2));
    }
};