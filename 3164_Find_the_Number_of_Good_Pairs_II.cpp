class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int>freq_nums2;
        for(int i=0;i<nums2.size();i++){
            freq_nums2[nums2[i]]++;
        }
        long long ans=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%k==0){
                int n=nums1[i]/k;
                for(int j=1;j*j<=n;j++){
                    if(n%j==0){
                        ans+=freq_nums2[j];
                        if(j!=n/j){
                            ans+=freq_nums2[n/j];
                        }
                    }
                }
            }
        }
        return ans;
    }
};