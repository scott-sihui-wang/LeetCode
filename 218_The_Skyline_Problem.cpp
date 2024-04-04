class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> sweep;
        multiset<int> heights{0};
        vector<vector<int>> ans;
        for(int i=0;i<buildings.size();i++){
            sweep.push_back(make_pair(buildings[i][0],-buildings[i][2]));
            sweep.push_back(make_pair(buildings[i][1],buildings[i][2]));
        }
        sort(sweep.begin(),sweep.end());
        int cur_height=0;
        for(int i=0;i<sweep.size();i++){
            if(sweep[i].second<0){
                heights.insert(-sweep[i].second);
            }
            else{
                heights.erase(heights.find(sweep[i].second));
            }
            if(cur_height!=*heights.rbegin()){
                cur_height=*heights.rbegin();
                ans.push_back({sweep[i].first,cur_height});
            }
        }
        return ans;
    }
};