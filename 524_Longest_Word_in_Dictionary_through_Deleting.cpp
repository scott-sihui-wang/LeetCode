class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        map<int,vector<string>>dict;
        sort(dictionary.begin(),dictionary.end());
        for(int i=0;i<dictionary.size();i++){
            int j=0,k=0;
            while(k<dictionary[i].size()){
                while(j<s.size() && s[j]!=dictionary[i][k]){
                    j++;
                }
                if(j==s.size())break;
                j++;
                k++;
            }
            if(!((j==s.size())&&(k<dictionary[i].size()))){
                dict[dictionary[i].size()].push_back(dictionary[i]);
            }
        }
        if(dict.size()==0)return string("");
        auto iter=dict.rbegin();
        return iter->second[0];
    }
};