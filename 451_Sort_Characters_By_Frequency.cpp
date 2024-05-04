class Solution {
public:
    string frequencySort(string s) {
        int freq[256];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        int max_freq=0;
        unordered_map<int,vector<char>>mp;
        for(int i=0;i<255;i++){
            if(freq[i]>0){
                max_freq=max(max_freq,freq[i]);
                mp[freq[i]].push_back(i);
            }
        }
        string ans("");
        for(int i=max_freq;i>=1;i--){
            for(int j=0;j<mp[i].size();j++){
                ans+=string(i,mp[i][j]);
            }
        }
        return ans;
    }
};