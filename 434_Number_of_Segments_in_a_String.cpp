class Solution {
public:
    int countSegments(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if((s[i]!=' ' && i>=s.size()-1) || (s[i]!=' ' && s[i+1]==' ')){
                ans++;
            }
        }
        return ans;
    }
};