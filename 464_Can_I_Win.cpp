class Solution {
public:
    bool DFS(int dp[], int state, int m, int t){
        if(dp[state]!=0){
            return dp[state]>0;
        }
        if(t<=0)return false;
        for(int i=1;i<=m;i++){
            if(!(state&(1<<(i-1))) && !DFS(dp, (state|(1<<(i-1))), m, t-i)){
                dp[state]=1;
                return true;
            }
        }
        dp[state]=-1;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<2) return true;
        if((maxChoosableInteger+1)*maxChoosableInteger/2<desiredTotal){
            return false;
        }
        else if((maxChoosableInteger+1)*maxChoosableInteger/2==desiredTotal){
            return maxChoosableInteger%2==1;
        }
        else{
            int dp[1<<20];
            memset(dp,0,sizeof(dp));
            return DFS(dp,0,maxChoosableInteger,desiredTotal);
        }
    }
};