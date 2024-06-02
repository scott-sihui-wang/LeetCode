class Solution {
public:
    int minimumChairs(string s) {
        int chairs=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E'){
                chairs++;
                ans=max(ans,chairs);
            }
            else if(s[i]=='L'){
                chairs--;
            }
        }
        return ans;
    }
};