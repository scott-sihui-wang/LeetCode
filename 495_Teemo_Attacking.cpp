class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        int right=-1;
        for(int i=0;i<timeSeries.size();i++){
            ans+=duration-max(0,right-timeSeries[i]);
            right=timeSeries[i]+duration;
        }
        return ans;
    }
};