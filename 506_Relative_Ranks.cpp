class Solution {
public:
    string numToRank(int i){
        if(i==0){
            return string("Gold Medal");
        }
        else if(i==1){
            return string("Silver Medal");
        }
        else if(i==2){
            return string("Bronze Medal");
        }
        else{
            return to_string(i+1);
        }
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>score_idx;
        for(int i=0;i<score.size();i++){
            score_idx.push_back({score[i],i});
        }
        sort(score_idx.begin(),score_idx.end());
        vector<string>ans(score.size());
        for(int i=0;i<score.size();i++){
            ans[score_idx[score.size()-1-i].second]=numToRank(i);
        }
        return ans;
    }
};