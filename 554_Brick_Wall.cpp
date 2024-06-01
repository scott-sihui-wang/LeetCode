class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int>pos_freq;
        int max_freq=0;
        for(int i=0;i<wall.size();i++){
            int pos=0;
            for(int j=0;j<wall[i].size()-1;j++){
                pos+=wall[i][j];
                pos_freq[pos]++;
                max_freq=max(max_freq,pos_freq[pos]);
            }
        }
        return wall.size()-max_freq;
    }
};