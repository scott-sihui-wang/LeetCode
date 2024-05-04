class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        char l1[20]={'Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p'};
        char l2[18]={'A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l'};
        char l3[14]={'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'};
        unordered_map<char,int> mp;
        for(int i=0;i<20;i++){
            mp[l1[i]]=1;
        }
        for(int i=0;i<18;i++){
            mp[l2[i]]=2;
        }
        for(int i=0;i<14;i++){
            mp[l3[i]]=3;
        }
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            int l=mp[words[i][0]];
            bool isSol=true;
            for(int j=1;j<words[i].size();j++){
                if(mp[words[i][j]]!=l){
                    isSol=false;
                    break;
                }
            }
            if(isSol){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};