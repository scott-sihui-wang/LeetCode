class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int d=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                d++;
                ans=max(ans,d);
            }
            else if(s[i]==')'){
                d--;
            }
        }
        return ans;
    }
};