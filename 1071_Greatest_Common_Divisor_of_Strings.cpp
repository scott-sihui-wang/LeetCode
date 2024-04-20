class Solution {
public:
    int GCD(int v1,int v2){
        int a=max(v1,v2),b=min(v1,v2);
        while(a%b!=0){
            int c=a%b;
            a=b;
            b=c;
        }
        return b;
    }
    string gcdOfStrings(string str1, string str2) {
        int gcd=GCD(str1.size(),str2.size());
        for(int i=0;i<gcd;i++){
            if(str1[i]!=str2[i]){
                return string("");
            }
        }
        for(int i=gcd;i<str1.size();i++){
            if(str1[i]!=str1[i%gcd]){
                return string("");
            }
        }
        for(int i=gcd;i<str2.size();i++){
            if(str2[i]!=str2[i%gcd]){
                return string("");
            }
        }
        return str1.substr(0,gcd);
    }
};