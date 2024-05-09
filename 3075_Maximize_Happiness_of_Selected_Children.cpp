class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end());
        int round=0;
        while(round<k){
            ans+=max(0,happiness[happiness.size()-1-round]-round);
            round++;
        }
        return ans;
    }
};