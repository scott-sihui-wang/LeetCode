class Solution {
public:
    bool feasible(vector<int>& piles,int s,int h){
        int ttl=0;
        for(int i=0;i<piles.size();i++){
            ttl+=piles[i]/s+(piles[i]%s==0?0:1);
        }
        return ttl<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1,high=piles[piles.size()-1];
        while(low<high){
            int mid=(low+high)/2;
            if(feasible(piles,mid,h)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};