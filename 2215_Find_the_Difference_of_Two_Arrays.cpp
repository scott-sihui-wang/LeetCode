class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1,n2;
        unordered_set<int>::iterator iter;
        vector<int> v1,v2;
        for(int i=0;i<nums1.size();i++){
            iter=n1.find(nums1[i]);
            if(iter==n1.end()){
                n1.insert(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            iter=n2.find(nums2[i]);
            if(iter==n2.end()){
                n2.insert(nums2[i]);
            }
        }
        for(iter=n1.begin();iter!=n1.end();iter++){
            if(n2.find(*iter)==n2.end()){
                v1.push_back(*iter);
            }
        }
        for(iter=n2.begin();iter!=n2.end();iter++){
            if(n1.find(*iter)==n1.end()){
                v2.push_back(*iter);
            }
        }
        vector<vector<int>>ans;
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};