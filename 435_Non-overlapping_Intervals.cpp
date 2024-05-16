class Solution {
public:
    static bool compare(pair<int,int>& pa,pair<int,int>& pb){
        return pa.second<pb.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        for(int i=0;i<intervals.size();i++){
            v.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(v.begin(),v.end(),compare);
        int u=v[0].second;
        int ans=1;
        for(int i=1;i<v.size();i++){
            if(v[i].first>=u){
                ans++;
                u=v[i].second;
            }
        }
        return intervals.size()-ans;
    }
};