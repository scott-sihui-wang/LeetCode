class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        const int sz=100000;
        bitset<sz>b;
        b[0]=true;
        for(int i=0;i<rewardValues.size();i++){
            int l=sz-rewardValues[i];
            int r=rewardValues[i];
            b=b | (b<<l>>l<<r);
        }
        int idx=2*rewardValues[rewardValues.size()-1]-1;
        while(!b[idx]){
            --idx;
        }
        return idx;
    }
};