class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> slope_cnt;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                slope_cnt[(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0])]++;
            }
            int M_cnt=0;
            for(unordered_map<double,int>::iterator iter=slope_cnt.begin();iter!=slope_cnt.end();iter++){
                M_cnt=max(M_cnt,iter->second);
            }
            ans=max(ans,M_cnt);
        }
        return ans+1;
    }
};