class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        int i=0,prev=0;
        while(i<s.size()){
            while(i<s.size() && s[i]!=' '){
                i++;
            }
            words.push_back(s.substr(prev,i-prev));
            i++;
            prev=i;
        }
        string ans;
        for(int i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
            ans+=words[i];
            if(i!=words.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};