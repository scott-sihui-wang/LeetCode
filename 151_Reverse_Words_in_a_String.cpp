class Solution {
public:
    string reverseWords(string s) {
        int len=s.length();
        int i=0;
        int begin[10000];
        int end[10000];
        int top=0;
        while(i<len){
            while(s[i]==' '){
                i++;
            }
            if(i>=len){
                break;
            }
            begin[top]=i;
            while(s[i]!=' '&& i<len){
                i++;
            }
            end[top]=i;
            top++;
        }
        string sol("");
        for(int i=top-1;i>=0;i--){
            sol.append(s.substr(begin[i],end[i]-begin[i]));
            if(i>0){
                sol.append(" ");
            }
        }
        return sol;
    }
};