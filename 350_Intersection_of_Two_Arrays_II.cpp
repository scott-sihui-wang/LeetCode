class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sol;
        int freq[1001];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<nums1.size();i++){
            freq[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(freq[nums2[i]]>0){
                freq[nums2[i]]--;
                sol.push_back(nums2[i]);
            }
        }
        return sol;
    }
};