class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>seq;
        int ans=0;
        int prev=0,idx=1;
        while(idx<s.size()){
            while(idx<s.size() && s[idx]==s[prev]){
                idx++;
            }
            if(idx<s.size()){
                seq.push_back(idx-prev);
                prev=idx;
            }
        }
        seq.push_back(idx-prev);
        for(int i=1;i<seq.size();i++){
            ans+=min(seq[i],seq[i-1]);
        }
        return ans;
    }
};