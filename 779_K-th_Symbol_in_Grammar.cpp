class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        int cnt=0;
        while(k!=0){
            if(k%2!=0)cnt++;
            k=k/2;
        }
        return cnt%2==0?0:1;
    }
};