class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.length();
        int valid[30001]={};
        valid[0]=0;
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                valid[i+1]=valid[i]+1;
            }
            else{
                valid[i+1]=valid[i]-1;
            }
        }
        int longest=0;
        for(int i=0;i<len-1;i++){
            int j=i+1;
            int l=0;
            for(;j<len+1;j++){
                if(valid[j]>valid[i]){
                    continue;
                }
                else if(valid[j]==valid[i]){
                    l=j-i;
                }
                else{
                    break;
                }
            }
            if(l>longest){
                longest=l;
            }
        }
        return longest;
    }
};