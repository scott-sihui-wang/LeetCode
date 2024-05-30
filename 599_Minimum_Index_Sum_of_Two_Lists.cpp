class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>pos;
        map<int,vector<string>>ans;
        for(int i=0;i<list1.size();i++){
            pos[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(pos.find(list2[i])!=pos.end()){
                ans[pos[list2[i]]+i].push_back(list2[i]);
            }
        }
        return ans.begin()->second;
    }
};