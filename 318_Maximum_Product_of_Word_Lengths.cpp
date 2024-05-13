class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>bits(n);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                bits[i] |= (1<<(words[i][j]-'a'));
            }
            for(int j=0;j<i;j++){
                if((bits[i] & bits[j])==0){
                    ans=max(ans,(int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return ans;
    }
};