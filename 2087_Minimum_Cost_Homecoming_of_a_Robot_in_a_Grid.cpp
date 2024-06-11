class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int step_x=(homePos[0]-startPos[0]>=0?1:-1);
        int step_y=(homePos[1]-startPos[1]>=0?1:-1);
        int ans=0;
        int i=startPos[0];
        while(i!=homePos[0]){
            i+=step_x;
            ans+=rowCosts[i];
        }
        i=startPos[1];
        while(i!=homePos[1]){
            i+=step_y;
            ans+=colCosts[i];
        }
        return ans;
    }
};