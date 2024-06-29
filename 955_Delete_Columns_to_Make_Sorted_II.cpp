class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        vector<int>idx;
        for(int i=0;i<strs.size()-1;i++){
            idx.push_back(i);
        }
        for(int i=0;i<strs[0].size();i++){
            bool del=false;
            vector<int>eq;
            for(int j=0;j<idx.size();j++){
                if(strs[idx[j]][i]>strs[idx[j]+1][i]){
                    ans++;
                    del=true;
                    break;
                }
                if(strs[idx[j]][i]==strs[idx[j]+1][i]){
                    eq.push_back(idx[j]);
                }
            }
            if(del==false){
                idx=eq;
            }
        }
        return ans;
    }
};