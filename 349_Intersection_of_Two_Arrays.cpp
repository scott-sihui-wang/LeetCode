class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sol;
        bool vis[1001];
        bool add[1001];
        memset(vis,0,sizeof(vis));
        memset(add,0,sizeof(add));
        for(int i=0;i<nums1.size();i++){
            vis[nums1[i]]=true;
        }
        for(int i=0;i<nums2.size();i++){
            if(vis[nums2[i]]==true && add[nums2[i]]==false){
                sol.push_back(nums2[i]);
                add[nums2[i]]=true;
            }
        }
        return sol;
    }
};