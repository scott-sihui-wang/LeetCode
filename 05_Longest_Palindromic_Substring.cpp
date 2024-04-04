class Solution {
public:
    int solve(string s,int idx,int len){
        int i;
        bool flag=false;
        for(i=len-1;i>=idx;i--){
            if(s[i]==s[idx]){
                flag=true;
                for(int j=0;j<(i-idx-1)/2;j++){
                    if(s[idx+1+j]!=s[i-1-j]){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    break;
                }
            }
        }
        return i-idx+1;
    }
    string longestPalindrome(string s) {
        int len=s.length();
        int longest=0;
        int idx=0;
        for(int i=0;i<len;i++){
            int cur=solve(s,i,len);
            if(cur>longest){
                longest=cur;
                idx=i;
            }
        }
        return s.substr(idx,longest);
    }
};