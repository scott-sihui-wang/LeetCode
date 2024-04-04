class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int len=s.length();
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=solve(s[i]-'a'+1);
        }
        while(k>1){
            sum=solve(sum);
            k--;
        }
        return sum;
    }
};