class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int> >sol;
        for(int i=0;i<secondList.size();i++){
            for(int j=0;j<firstList.size();j++){
                if(max(secondList[i][0],firstList[j][0])<=min(secondList[i][1],firstList[j][1])){
                    vector<int>sub_sol;
                    sub_sol.push_back(max(firstList[j][0],secondList[i][0]));
                    sub_sol.push_back(min(firstList[j][1],secondList[i][1]));
                    sol.push_back(sub_sol);
                }
            }
        }
        return sol;
    }
};