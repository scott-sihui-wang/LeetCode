class Solution {
public:
    int binarySearch(vector<int>& arr,int target){
        int i=0,j=arr.size()-1;
        while(i<j){
            int m=(i+j)/2;
            if(arr[m]>target){
                i=m+1;
            }
            else{
                j=m;
            }
        }
        return i;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int idx=binarySearch(grid[i],-1);
            if(grid[i][idx]<=-1){
                ans+=grid[i].size()-idx;
            }
        }
        return ans;
    }
};