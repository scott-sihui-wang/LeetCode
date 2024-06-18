class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        int startZero=-1;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==0 && startZero==-1){
                startZero=i;
            }
            if(seats[i]==1 && startZero!=-1){
                if(startZero==0){
                    ans=max(ans,i-startZero);
                }
                else{
                    ans=max(ans,(i-startZero-1)/2+1);
                }
                startZero=-1;
            }
        }
        if(startZero!=-1){
            ans=max(ans,(int)seats.size()-startZero);
        }
        return ans;
    }
};