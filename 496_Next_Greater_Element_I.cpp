class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> num_list;
        unordered_map<int,int>::iterator iter;
        vector<int>sol;
        for(int i=0;i<nums2.size();i++){
            num_list[nums2[i]]=i;
        }
        for(int i=0;i<nums1.size();i++){
            iter=num_list.find(nums1[i]);
            int j=iter->second+1;
            for(;j<nums2.size();j++){
                if(nums2[j]>nums1[i])break;
            }
            if(j>=nums2.size()){
                sol.push_back(-1);
            }
            else{
                sol.push_back(nums2[j]);
            }
        }
        return sol;
    }
};