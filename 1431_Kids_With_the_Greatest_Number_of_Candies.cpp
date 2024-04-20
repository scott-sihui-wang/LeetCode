class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int sz=candies.size();
        int maximum=candies[0];
        vector<bool>ans(sz);
        for(int i=1;i<sz;i++){
            maximum=max(maximum,candies[i]);
        }
        for(int i=0;i<sz;i++){
            ans[i]=(candies[i]+extraCandies>=maximum);
        }
        return ans;
    }
};