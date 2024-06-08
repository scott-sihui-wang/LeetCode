class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx){
        if(idx==special.size()){
            int ans=0;
            for(int i=0;i<price.size();i++){
                ans+=price[i]*needs[i];
            }
            return ans;
        }
        int rej=solve(price,special,needs,idx+1);
        for(int i=0;i<needs.size();i++){
            if(needs[i]-special[idx][i]<0) return rej;
        }
        for(int i=0;i<needs.size();i++){
            needs[i]-=special[idx][i];
        }
        int acc=special[idx][price.size()]+solve(price,special,needs,idx);
        for(int i=0;i<needs.size();i++){
            needs[i]+=special[idx][i];
        }
        return min(rej,acc);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price,special,needs,0);
    }
};