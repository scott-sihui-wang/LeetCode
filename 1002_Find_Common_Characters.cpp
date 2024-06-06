class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int freq_a[26];
        for(int i=0;i<26;i++){
            freq_a[i]=INT_MAX;
        }
        for(int i=0;i<words.size();i++){
            int freq_b[26];
            memset(freq_b,0,sizeof(freq_b));
            for(int j=0;j<words[i].size();j++){
                freq_b[words[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                freq_a[j]=min(freq_a[j],freq_b[j]);
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            for(int j=0;j<freq_a[i];j++){
                ans.push_back(string(1,'a'+i));
            }
        }
        return ans;
    }
};