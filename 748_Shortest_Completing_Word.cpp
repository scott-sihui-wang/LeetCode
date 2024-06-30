class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int>freq;
        for(int i=0;i<licensePlate.size();i++){
            if(licensePlate[i]>='a' && licensePlate[i]<='z'){
                freq[licensePlate[i]]++;
            }
            else if(licensePlate[i]>='A' && licensePlate[i]<='Z'){
                freq[licensePlate[i]-'A'+'a']++;
            }
        }
        int shortest=INT_MAX,idx=-1;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int>freq_w;
            for(int j=0;j<words[i].size();j++){
                if(words[i][j]>='a' && words[i][j]<='z'){
                    freq_w[words[i][j]]++;
                }
                else if(words[i][j]>='A' && words[i][j]<='Z'){
                    freq_w[words[i][j]-'A'+'a']++;
                }
            }
            bool contain=true;
            for(auto iter=freq.begin();iter!=freq.end();iter++){
                if(freq_w.find(iter->first)==freq_w.end() || freq_w[iter->first]<iter->second){
                    contain=false;
                    break;
                }
            }
            if(contain){
                if(words[i].size()<shortest){
                    shortest=words[i].size();
                    idx=i;
                }
            }
        }
        return words[idx];
    }
};