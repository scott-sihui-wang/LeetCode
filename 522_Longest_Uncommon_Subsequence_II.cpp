class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans=-1;
        int n=strs.size();
        for(int i=0;i<n;i++){
            bool uncommon=true;
            for(int j=0;j<n;j++){
                if(j!=i && strs[i].size()<=strs[j].size()){
                    int idx_i=0,idx_j=0;
                    for(;idx_j<strs[j].size();idx_j++){
                        if(idx_i<strs[i].size() && strs[i][idx_i]==strs[j][idx_j]){
                            idx_i++;
                        }
                    }
                    if(idx_i==strs[i].size()){
                        uncommon=false;
                        break;
                    }
                }
            }
            if(uncommon){
                ans=max(ans,(int)strs[i].size());
            }
        }
        return ans;
    }
};