class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int pf[n+1];
        int val=0;
        pf[0]=val;
        for(int i=0;i<n;i++){
            val^=arr[i];
            pf[i+1]=val;
        }
        cout<<endl;
        int ans=0;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                if((pf[j]^pf[i-1])==0){
                    ans+=j-i;
                }
            }
        }
        return ans;
    }
};