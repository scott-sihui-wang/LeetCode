class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int>freq;
        map<int,long long>dp;
        map<int,long long>prev_max;
        for(int i=0;i<power.size();i++){
            freq[power[i]]++;
        }
        long long ans=0;
        long long prev=0;
        for(auto iter=freq.begin();iter!=freq.end();iter++){
            dp[iter->first]+=(long long)iter->first*iter->second;
            if(prev_max.size()>0){
                for(auto iter2=prev_max.rbegin();iter2!=prev_max.rend();iter2++){
                    if(iter2->first<iter->first-2){
                        dp[iter->first]+=prev_max[iter2->first];
                        break;
                    }
                }
            }
            prev_max[iter->first]=max(prev,dp[iter->first]);
            prev=prev_max[iter->first];
        }
        return prev;
    }
};