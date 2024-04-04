class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        int pay[len];
        pay[0]=0;
        pay[1]=min(cost[0],cost[1]);
        for(int i=2;i<len;i++){
            pay[i]=min(pay[i-2]+cost[i-1],pay[i-1]+cost[i]);
        }
        return pay[len-1];
    }
};