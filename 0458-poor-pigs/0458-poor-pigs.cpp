class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempts=(minutesToTest)/minutesToDie;
        int pigs=0;
        while(pow(attempts+1,pigs)<buckets){
            pigs++;
        }
        return pigs;
    }
};