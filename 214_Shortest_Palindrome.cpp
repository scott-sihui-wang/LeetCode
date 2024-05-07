class Solution {
public:
    string shortestPalindrome(string s) {
        string s_rev;
        for(int i=s.size()-1;i>=0;i--){
            s_rev+=s[i];
        }
        string str=s+"#"+s_rev;
        int KMP[str.size()];
        KMP[0]=0;
        for(int i=1;i<str.size();i++){
            int j=KMP[i-1];
            while(j>0 && str[j]!=str[i])j=KMP[j-1];
            if(str[j]==str[i]){
                KMP[i]=j+1;
            }
            else{
                KMP[i]=0;
            }
        }
        string sf=s.substr(KMP[str.size()-1]);
        reverse(sf.begin(),sf.end());
        return sf+s;
    }
};