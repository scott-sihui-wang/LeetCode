class Solution {
public:
    bool DFS(vector<int>& matchsticks, int idx, int sum[], int len){
        if(idx==matchsticks.size()){
            return sum[0]==len && sum[1]==len && sum[2]==len && sum[3]==len;
        }
        for(int i=0;i<4;i++){
            if(sum[i]+matchsticks[idx]<=len){
                sum[i]+=matchsticks[idx];
                bool ans=DFS(matchsticks,idx+1,sum,len);
                if(ans)return true;
                sum[i]-=matchsticks[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        int n=matchsticks.size();
        for(int i=0;i<n;i++){
            sum+=matchsticks[i];
        }
        if(sum%4!=0)return false;
        int len=sum/4;
        int s[4];
        memset(s,0,sizeof(s));
        sort(matchsticks.rbegin(),matchsticks.rend());
        return DFS(matchsticks,0,s,len);
    }
};