class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T=minutesToTest/minutesToDie;
        return ceil(log2(buckets)/log2(T+1));
    }
};