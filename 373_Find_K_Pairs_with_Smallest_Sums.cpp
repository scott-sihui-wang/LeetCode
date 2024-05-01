class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(q.size()<k){
                    q.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else if(q.size()==k){
                    if(nums1[i]+nums2[j]<q.top().first){
                        q.pop();
                        q.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                    }
                    else{
                        break;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> v;
            v.push_back(q.top().second.first);
            v.push_back(q.top().second.second);
            ans.push_back(v);
            q.pop();
        }
        return ans;
    }
};