class Solution {
public:
    int countSubstrings(string s) {
        int sol=0;
        int len=s.length();
        sol+=len;
        for(int i=1;i<len;i++){
            for(int j=0;j<len-i;j++){
                bool isPalindromic=true;
                for(int k=0;k<(i+1)/2;k++){
                    if(s[j+k]!=s[j+i-k]){
                        isPalindromic=false;
                        break;
                    }
                }
                if(isPalindromic==true){
                    sol++;
                }
            }
        }
        return sol;
    }
};