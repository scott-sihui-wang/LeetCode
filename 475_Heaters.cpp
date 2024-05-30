class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n=houses.size(),m=heaters.size();
        vector<int>ans(n,INT_MAX);
        int N,M;
        for(N=0,M=0;N<n && M<m;){
            if(houses[N]<=heaters[M]){
                ans[N]=min(ans[N],heaters[M]-houses[N]);
                N++;
            }
            else{
                M++;
            }
        }
        for(N=n-1,M=m-1;N>=0 && M>=0;){
            if(houses[N]>=heaters[M]){
                ans[N]=min(ans[N],houses[N]-heaters[M]);
                N--;
            }
            else{
                M--;
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            res=max(res,ans[i]);
        }
        return res;
    }
};