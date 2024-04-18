class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        sort(points.begin(),points.end());
        int y=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=y){
                y=min(y,points[i][1]);
            }
            else{
                y=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};