class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n=points.size();
        vector<int> pts;
        for(int i=0;i<n;i++){
            pts.push_back(points[i][0]);
        }
        sort(pts.begin(),pts.end());
        int j=0,k=0,ans=1;
        while(j<n){
            while(j<n && pts[j]<=pts[k]+w){
                j++;
            }
            if(j<n){
                ans++;
                k=j;
            }
        }
        return ans;
    }
};