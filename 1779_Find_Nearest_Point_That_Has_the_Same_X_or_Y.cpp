class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_dist=INT_MAX;
        int dist;
        int idx=-1;
        int len=points.size();
        for(int i=0;i<len;i++){
            if(points[i][0]==x){
                dist=abs(points[i][1]-y);
                if(dist<min_dist){
                    min_dist=dist;
                    idx=i;
                }
            }
            else if(points[i][1]==y){
                dist=abs(points[i][0]-x);
                if(dist<min_dist){
                    min_dist=dist;
                    idx=i;
                }
            }
        }
        return idx;
    }
};