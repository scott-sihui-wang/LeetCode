class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        for(int i=0;i<n;i++){
            int time=0;
            int j=i;
            while(j!=headID){
                time+=informTime[manager[j]];
                j=manager[j];
            }
            ans=max(ans,time);
        }
        return ans;
    }
};