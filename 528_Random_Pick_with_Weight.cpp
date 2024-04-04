class Solution {
public:
    
    int sum[10000];
    int top=-1;
    
    Solution(vector<int>& w) {
        sum[++top]=w[0];
        for(int i=1;i<w.size();i++){
            top++;
            sum[top]=sum[top-1]+w[top];
        }
    }
    
    int pickIndex() {
        int val=rand()%sum[top]+1;
        int sol=0;
        while(sum[sol]<val){
            sol++;
        }
        return sol;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */