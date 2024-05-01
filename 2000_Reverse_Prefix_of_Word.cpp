class Solution {
public:
    string reverse(string s){
        string ans="";
        for(int i=0;i<s.size();i++){
            ans+=s[s.size()-1-i];
        }
        return ans;
    }
    string reversePrefix(string word, char ch) {
        int i=0;
        while(i<word.size() && word[i]!=ch){
            i++;
        }
        if(i==word.size())return word;
        string p1=reverse(word.substr(0,i+1));
        string p2=word.substr(i+1);
        return p1+p2;
    }
};