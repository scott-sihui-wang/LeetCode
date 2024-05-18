class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>ans;
        for(int i=max(k-(int)nums2.size(),0);i<=min(k,(int)nums1.size());i++){
            ans=max(ans,maxMerge(maxNumSingle(nums1,i),maxNumSingle(nums2,k-i)));
        }
        return ans;
    }
    vector<int> maxNumSingle(vector<int> nums, int k){
        int omit=nums.size()-k;
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && s.top()<nums[i] && omit>0){
                s.pop();
                omit--;
            }
            s.push(nums[i]);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        ans.resize(k);
        return ans;
    }
    vector<int> maxMerge(vector<int> nums1, vector<int> nums2){
        vector<int> ans;
    	while(!nums1.empty() || !nums2.empty()){
    		if(nums1>nums2){
        		ans.push_back(nums1[0]);
        		nums1.erase(nums1.begin());
			}
			else{
				ans.push_back(nums2[0]);
				nums2.erase(nums2.begin());
			}
		}
        return ans;
    }
};