class Solution {
public:
    bool clockwise(vector<int>& v1, vector<int>& v2, vector<int>& v3){
        return (v2[0]-v1[0])*(v3[1]-v1[1])-(v2[1]-v1[1])*(v3[0]-v1[0])>=0;
    }
    static bool compare(vector<int>& v1, vector<int>& v2){
        return v1[0]<v2[0] || (v1[0]==v2[0] && v1[1]<v2[1]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;
        sort(trees.begin(),trees.end(),compare);
        for(int i=0;i<trees.size();i++){
            while(ans.size()>1 && !clockwise(ans[ans.size()-2],ans[ans.size()-1],trees[i])){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        if(ans.size()==trees.size())return ans;
        for(int i=trees.size()-2;i>=0;i--){
            while(ans.size()>1 && !clockwise(ans[ans.size()-2],ans[ans.size()-1],trees[i])){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        return ans;
    }
};