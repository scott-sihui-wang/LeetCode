class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> >sol;
        int len=intervals.size();
        if(len==0){
            sol.push_back(newInterval);
            return sol;
        }
        bool vis[len];
        memset(vis,0,sizeof(vis));
        int idx=-1;
        int lower=newInterval[0];
        int upper=newInterval[1];
        for(int i=0;i<len;i++){
            int l=max(intervals[i][0],lower);
            int r=min(intervals[i][1],upper);
            if(l>intervals[i][0]){
                idx=i;
            }
            if(l<=r){
                vis[i]=true;
                lower=min(intervals[i][0],lower);
                upper=max(intervals[i][1],upper);
            }
        }
        vector<int> merged;
        merged.push_back(lower);
        merged.push_back(upper);
        if(idx==-1){
            sol.push_back(merged);
        }
        for(int i=0;i<len;i++){
            if(vis[i]==false){
                vector<int>tmp;
                tmp.push_back(intervals[i][0]);
                tmp.push_back(intervals[i][1]);
                sol.push_back(tmp);
            }
            if(idx==i){
                sol.push_back(merged);
            }
        }
        return sol;
    }
};