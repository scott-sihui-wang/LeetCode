class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum=0,n=machines.size();
        for(int i=0;i<n;i++){
            sum+=machines[i];
        }
        if(sum%n!=0)return -1;
        int avg=sum/n;
        int flow[n][2];
        int prev=0,ans=0;
        for(int i=0;i<n;i++){
            flow[i][0]=-prev;
            flow[i][1]=avg-(machines[i]+flow[i][0]);
            prev=flow[i][1];
            if(flow[i][0]<=0 && flow[i][1]<=0){
                ans=max(ans,abs(flow[i][0]+flow[i][1]));
            }
            else if(flow[i][0]<=0 && flow[i][1]>0){
                ans=max(ans,max(-flow[i][0],flow[i][1]));
            }
            else if(flow[i][0]>0 && flow[i][1]<=0){
                ans=max(ans,max(flow[i][0],-flow[i][1]));
            }
            else{
                ans=max(ans,max(flow[i][0],flow[i][1]));
            }
        }
        return ans;
    }
};