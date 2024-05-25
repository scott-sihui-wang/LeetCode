class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        vector<unordered_map<double,int>>v(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double dist=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                v[i][dist]++;
                v[j][dist]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(auto iter=v[i].begin();iter!=v[i].end();iter++){
                int num=iter->second;
                ans+=num*(num-1);
            }
        }
        return ans;
    }
};