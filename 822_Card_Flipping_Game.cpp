class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int>allNums,bothSides;
        for(int i=0;i<fronts.size();i++){
            allNums.insert(fronts[i]);
            allNums.insert(backs[i]);
            if(fronts[i]==backs[i]){
                bothSides.insert(fronts[i]);
            }
        }
        for(auto iter=allNums.begin();iter!=allNums.end();iter++){
            if(bothSides.find(*iter)==bothSides.end()){
                return *iter;
            }
        }
        return 0;
    }
};