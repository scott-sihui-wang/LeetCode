class Solution {
public:
    int row,col,size;
    set<int>slots;
    Solution(int m, int n) {
        row=m;
        col=n;
        size=m*n;
    }
    
    vector<int> flip() {
        int r=rand()%size;
        while(slots.find(r)!=slots.end()){
            r=(++r)%size;
        }
        slots.insert(r);
        return {r/col,r%col};
    }
    
    void reset() {
        slots.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */