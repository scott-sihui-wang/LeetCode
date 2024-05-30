class Solution {
public:
    int area;
    int size;
    vector<int> accumulated_area;
    vector<vector<int>> rect;

    Solution(vector<vector<int>>& rects) {
        size=rects.size();
        area=0;
        accumulated_area.push_back(area);
        for(int i=0;i<size;i++){
            rect.push_back(rects[i]);
            area+=(rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            accumulated_area.push_back(area);
        }
    }
    
    vector<int> pick() {
        int r=rand()%area;
        int i=0;
        for(;i<size;i++){
            if(r>=accumulated_area[i] && r<accumulated_area[i+1]){
                return {rect[i][0]+(r-accumulated_area[i])%(rect[i][3]-rect[i][1]+1),rect[i][1]+(r-accumulated_area[i])/(rect[i][3]-rect[i][1]+1)};
            }
        }
        return {INT_MIN,INT_MIN};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */