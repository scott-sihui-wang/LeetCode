class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int>idx;
        for(int i=0;i<t.size();i++){
            idx[t[i]]=i;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=abs(i-idx[s[i]]);
        }
        return ans;
    }
};