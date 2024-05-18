class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return false;
        vector<int>idx;
        int diff=0;
        unordered_map<char,int>freq;
        bool same=false;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                diff++;
                idx.push_back(i);
            }
            if(diff>2)return false;
            freq[s[i]]++;
            if(freq[s[i]]>1)same=true;
        }
        if(diff==1)return false;
        if(diff==0) return same;
        return s[idx[0]]==goal[idx[1]] && s[idx[1]]==goal[idx[0]];
    }
};