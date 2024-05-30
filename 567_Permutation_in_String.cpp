class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        vector<int>freq(26,0);
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        set<vector<int>>s;
        s.insert(freq);
        vector<int>freq2(26,0);
        for(int i=0;i<s1.size();i++){
            freq2[s2[i]-'a']++;
        }
        if(s.find(freq2)!=s.end())return true;
        for(int i=s1.size();i<s2.size();i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-s1.size()]-'a']--;
            if(s.find(freq2)!=s.end())return true;
        }
        return false;
    }
};