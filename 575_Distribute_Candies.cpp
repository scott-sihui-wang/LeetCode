class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> candyTy;
        for(int i=0;i<candyType.size();i++){
            candyTy.insert(candyType[i]);
        }
        return min(candyType.size()/2,candyTy.size());
    }
};