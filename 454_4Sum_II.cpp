class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>sum_freq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                sum_freq[nums1[i]+nums2[j]]++;
            }
        }
        int ans=0;
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                ans+=sum_freq[-nums3[i]-nums4[j]];
            }
        }
        return ans;
    }
};