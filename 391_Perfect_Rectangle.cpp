class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>freq;
        for(int i=0;i<rectangles.size();i++){
            freq[{rectangles[i][0],rectangles[i][1]}]++;
            freq[{rectangles[i][2],rectangles[i][1]}]--;
            freq[{rectangles[i][0],rectangles[i][3]}]--;
            freq[{rectangles[i][2],rectangles[i][3]}]++;
        }
        int cnt=0;
        for(map<pair<int,int>,int>::iterator iter=freq.begin();iter!=freq.end();iter++){
            if(iter->second!=0){
                if(iter->second!=1 && iter->second!=-1)return false;
                cnt++;
            }
        }
        return cnt==4;
    }
};