class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int>dict;
        int n_words=words.size();
        int len_word=words[0].size();
        for(int i=0;i<n_words;i++){
            dict[words[i]]++;
        }
        for(int i=0;i<len_word;i++){
            unordered_map<string,int>dict2;
            for(int j=0;i+(j+n_words)*len_word<=(int)s.size();j++){
                if(j==0){
                    for(int k=0;k<n_words;k++){
                        dict2[s.substr(i+(j+k)*len_word,len_word)]++;
                    }
                }
                else{
                    if(dict2[s.substr(i+(j-1)*len_word,len_word)]>1){
                        dict2[s.substr(i+(j-1)*len_word,len_word)]--;
                    }
                    else{
                        dict2.erase(s.substr(i+(j-1)*len_word,len_word));
                    }
                    dict2[s.substr(i+(j+n_words-1)*len_word,len_word)]++;
                }
                if(dict==dict2)ans.push_back(i+j*len_word);
            }
        }
        return ans;
    }
};