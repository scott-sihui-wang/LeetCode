class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int MOD=1000000007;
        vector<long long> arr(n,1);
        for(int i=0;i<k;i++){
            for(int j=1;j<n;j++){
                arr[j]=(arr[j-1]+arr[j])%MOD;
            }
        }
        return arr[n-1];
    }
};