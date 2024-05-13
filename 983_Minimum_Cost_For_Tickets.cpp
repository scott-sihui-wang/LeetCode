class Solution {
public:
    int binarySearch(vector<int>& days, int day, int begin, int end){
        while(begin<=end){
            int mid=(begin+end)/2;
            if(days[mid]>=day){
                end=mid-1;
            }
            else{
                begin=mid+1;
            }
        }
        return begin;
    }
    int solve(int dp[],vector<int>& days,vector<int>& costs,int i){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=min(min(costs[0]+solve(dp,days,costs,binarySearch(days,days[i]+1,i+1,days.size()-1)),costs[1]+solve(dp,days,costs,binarySearch(days,days[i]+7,i+1,days.size()-1))),costs[2]+solve(dp,days,costs,binarySearch(days,days[i]+30,i+1,days.size()-1)));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return solve(dp,days,costs,0);
    }
};