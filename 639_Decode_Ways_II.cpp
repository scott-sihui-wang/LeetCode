class Solution {
public:
    int decode_1digit(char c){
        if(c=='*'){
            return 9;
        }
        else if(c>='1' && c<='9'){
            return 1;
        }
        else{
            return 0;
        }
    }
    int decode_2digits(string s){
        if(s[0]=='*' && s[1]=='*'){
            return 15;
        }
        else if(s[0]=='*' && s[1]>='0' && s[1]<='9'){
            if(s[1]>='0' && s[1]<='6'){
                return 2;
            }
            else{
                return 1;
            }
        }
        else if(s[0]>='0' && s[0]<='9' && s[1]=='*'){
            if(s[0]=='1'){
                return 9;
            }
            else if(s[0]=='2'){
                return 6;
            }
            else{
                return 0;
            }
        }
        else if(s[0]>='0' && s[0]<='9' && s[1]>='0' && s[1]<='9'){
            if(s[0]=='1'){
                return 1;
            }
            else if(s[0]=='2' && s[1]>='0' && s[1]<='6'){
                return 1;
            }
            else{
                return 0;
            }
        }
        return 0;
    }
    int numDecodings(string s) {
        int n=s.size();
        int MOD=1000000007;
        if(n==1){
            return decode_1digit(s[0]);
        }
        else if(n==2){
            return decode_2digits(s)+decode_1digit(s[0])*decode_1digit(s[1]);
        }
        long long dp[n];
        dp[0]=decode_1digit(s[0]);
        dp[1]=decode_2digits(s.substr(0,2))+decode_1digit(s[0])*decode_1digit(s[1]);
        for(int i=2;i<n;i++){
            dp[i]=((dp[i-2]*decode_2digits(s.substr(i-1,2)))%MOD+(dp[i-1]*decode_1digit(s[i]))%MOD)%MOD;
        }
        return dp[n-1];
    }
};