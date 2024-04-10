class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int left_max=INT_MIN,right_max=INT_MIN;
        int l=0,r=height.size()-1;
        while(l<=r){
            if(left_max<right_max){
                if(left_max>height[l]){
                    ans+=left_max-height[l];
                }
                else{
                    left_max=height[l];
                }
                l++;
            }
            else{
                if(right_max>height[r]){
                    ans+=right_max-height[r];
                }
                else{
                    right_max=height[r];
                }
                r--;
            }
        }
        return ans;
    }
};