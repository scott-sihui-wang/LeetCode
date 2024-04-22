class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(vector<int>(spells.size(),0));
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int begin=0,end=potions.size()-1;
            while(begin<=end){
                int mid=(begin+end)/2;
                if((long long)spells[i]*(long long)potions[mid]>=success){
                    end=mid-1;
                }
                else{
                    begin=mid+1;
                }
            }
            ans[i]=potions.size()-begin;
        }
        return ans;
    }
};