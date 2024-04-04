class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> sol(1<<n,0);
        int begin=1;
        int end=2;
        int add=1;
        for(int i=0;i<n;i++){
            for(int j=begin;j<end;j++){
                sol[j]=sol[end-1-j]+add;
            }
            begin*=2;
            end*=2;
            add*=2;
        }
        return sol;        
    }
};