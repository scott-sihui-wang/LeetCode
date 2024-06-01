class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for(int i=0;i<n-k-1;i++){
            ans.push_back(i+1);
        }
        for(int i=n-k;i<=n-(k+1)/2;i++){
            ans.push_back(i);
            if(2*n-k-i>i){
                ans.push_back(2*n-k-i);
            }
        }
        return ans;
    }
};