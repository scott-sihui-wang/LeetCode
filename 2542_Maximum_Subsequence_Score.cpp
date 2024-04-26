class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end(),greater<>());
        priority_queue<int,vector<int>,greater<int>>p;
        long long sum=0,ans=0;
        for(int i=0;i<nums2.size();i++){
            if(p.size()<k){
                p.push(v[i].second);
                sum+=(long long)v[i].second;
            }
            if(p.size()==k){
                ans=max(ans,(long long)v[i].first*sum);
                sum-=p.top();
                p.pop();
            }
        }
        return ans;
    }
};