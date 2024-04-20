class Solution {
public:
    string removeStars(string s) {
        int sz=s.size();
        char res[sz];
        int top=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                res[++top]=s[i];
            }
            else{
                --top;
            }
        }
        string ans="";
        for(int i=0;i<=top;i++){
            ans+=string(1,res[i]);
        }
        return ans;
    }
};