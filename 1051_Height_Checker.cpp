class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ordered_heights(heights.size());
        for(int i=0;i<heights.size();i++){
            ordered_heights[i]=heights[i];
        }
        sort(ordered_heights.begin(),ordered_heights.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=ordered_heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};