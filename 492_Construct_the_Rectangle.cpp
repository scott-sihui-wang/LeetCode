class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W,L;
        for(int i=1;i*i<=area;i++){
            if(area%i==0){
                W=i;
                L=area/i;
            }
        }
        vector<int>ans;
        ans.push_back(L);
        ans.push_back(W);
        return ans;
    }
};