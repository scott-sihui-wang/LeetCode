class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long freq[24];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<hours.size();i++){
            freq[hours[i]%24]++;
        }
        long long ans=0;
        ans+=freq[0]*(freq[0]-1)/2;
        ans+=freq[12]*(freq[12]-1)/2;
        for(int i=1;i<=11;i++){
            ans+=freq[i]*freq[24-i];
        }
        return ans;
    }
};