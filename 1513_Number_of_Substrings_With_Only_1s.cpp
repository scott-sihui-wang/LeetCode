class Solution {
public:
    int numSub(string s) {
        int len=s.length();
        int i=0;
        long long sol=0;
        while(i<len){
            int start=i;
            while(i+1<len && s[i]==s[i+1]){
                i++;
            }
            if(s[i]=='1'){
                long long tmp=(i+1-start);
                sol+=tmp*(tmp+1)/2;
            }
            i++;
        }
        int m=1e9+7;
        return sol%m;
    }
};