class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        vector<pair<int,vector<int>>>val(n);
        for(int i=0;i<vals.size();i++){
            val[i]={vals[i],{}};
        }
        for(int i=0;i<edges.size();i++){
            val[edges[i][0]].second.push_back(vals[edges[i][1]]);
            val[edges[i][1]].second.push_back(vals[edges[i][0]]);
        }
        int ans=INT_MIN;
        for(auto iter=val.begin();iter!=val.end();iter++){
            int sum=iter->first;
            sort(iter->second.begin(),iter->second.end());
            int sz=iter->second.size();
            for(int i=sz-1;i>=sz-k && i>=0;i--){
                if(iter->second[i]>=0){
                    sum+=iter->second[i];
                }
                else{
                    break;
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};