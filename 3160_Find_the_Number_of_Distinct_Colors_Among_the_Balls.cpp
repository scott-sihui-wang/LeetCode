class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,set<int>>color;
        unordered_map<int,int>position;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(position.find(queries[i][0])!=position.end()){
                color[position[queries[i][0]]].erase(queries[i][0]);
                if(color[position[queries[i][0]]].size()==0){
                    color.erase(position[queries[i][0]]);
                }
            }
            position[queries[i][0]]=queries[i][1];
            color[position[queries[i][0]]].insert(queries[i][0]);
            ans.push_back(color.size());
        }
        return ans;
    }
};