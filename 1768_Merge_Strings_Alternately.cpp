class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0;
        while(i<word1.size() && j<word2.size()){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        for(;i<word1.size();i++){
            ans+=word1[i];
        }
        for(;j<word2.size();j++){
            ans+=word2[j];
        }
        return ans;
    }
};