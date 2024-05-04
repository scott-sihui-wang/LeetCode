class Solution {
public:
    char toUpperChar(char c){
        return 'A'+(c-'a');
    }
    string licenseKeyFormatting(string s, int k) {
        string ans("");
        int cnt=k;
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
                ans+=s[i];
                cnt--;
            }
            else if(s[i]>='a' && s[i]<='z'){
                ans+=toUpperChar(s[i]);
                cnt--;
            }
            if(cnt==0){
                ans+='-';
                cnt=k;
            }
        }
        reverse(ans.begin(),ans.end());
        int j=0;
        while(j<ans.size() && ans[j]=='-'){
            j++;
        }
        return ans.substr(j);
    }
};