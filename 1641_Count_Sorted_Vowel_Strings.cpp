class Solution {
public:
    void solve(int r,int n,int k,int& ttl){
        if(r==n){
            ttl+=5-k;
        }
        else{
            for(int i=k;i<5;i++){
                solve(r+1,n,i,ttl);
            }
        }
    }
    int countVowelStrings(int n) {
        int ttl=0;
        solve(1,n,0,ttl);
        return ttl;
    }
};