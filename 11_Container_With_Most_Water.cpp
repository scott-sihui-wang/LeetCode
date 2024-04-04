class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int h=height[left]>height[right]?height[right]:height[left];
            int area0=h*(right-left);
            if(area0>area){
                area=area0;
            }
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return area;
    }
};