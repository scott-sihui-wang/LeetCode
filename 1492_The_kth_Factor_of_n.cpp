class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factor;
        int cnt=0;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                cnt++;
                if(k==cnt){
                    return i;
                }
                factor.push_back(i);
            }
        }
        int len=factor.size();
        if(factor[len-1]*factor[len-1]==n){
            if(k>2*len-1){
                return -1;
            }
            else{
                return n/factor[2*len-1-k];
            }
        }
        else{
            if(k>2*len){
                return -1;
            }
            else{
                return n/factor[2*len-k];
            }
        }
    }
};