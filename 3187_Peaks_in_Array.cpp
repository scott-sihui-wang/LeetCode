class Solution {
public:
    int *segTree;
    void buildTree(int *segTree, int idx, int left, int right, vector<int>& nums){
        if(left>right)return;
        if(left==right){
            segTree[idx]=nums[left];
            return;
        }
        int mid=(left+right)/2;
        buildTree(segTree,2*idx+1,left,mid,nums);
        buildTree(segTree,2*idx+2,mid+1,right,nums);
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
    }
    void update(int *segTree, int idx, int left, int right, int index, int val){
        if(left>right)return;
        if(left==right){
            segTree[idx]=val;
            return;
        }
        int mid=(left+right)/2;
        if(index<=mid){
            update(segTree,2*idx+1,left,mid,index,val);
        }
        else{
            update(segTree,2*idx+2,mid+1,right,index,val);
        }
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
    }
    int sum(int *segTree, int idx, int left, int right, int left_s, int right_s){
        if(left>right_s || right<left_s)return 0;
        if(left_s<=left && right_s>=right)return segTree[idx];
        int mid=(left+right)/2;
        return sum(segTree,2*idx+1,left,mid,left_s,right_s)+sum(segTree,2*idx+2,mid+1,right,left_s,right_s);
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int *segTree=new int[4*n];
        vector<int>peaks(n,0);
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                peaks[i]=1;
            }
        }
        buildTree(segTree,0,0,n-1,peaks);
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                if(queries[i][1]==queries[i][2]){
                    ans.push_back(0);
                    continue;
                }
                int res=sum(segTree,0,0,n-1,queries[i][1],queries[i][2]);
                if(peaks[queries[i][1]]==1){
                    res--;
                }
                if(peaks[queries[i][2]]==1){
                    res--;
                }
                ans.push_back(res);
            }
            else{
                nums[queries[i][1]]=queries[i][2];
                if(queries[i][1]>1 && nums[queries[i][1]-1]>nums[queries[i][1]] && nums[queries[i][1]-1]>nums[queries[i][1]-2]){
                    update(segTree,0,0,n-1,queries[i][1]-1,1);
                    peaks[queries[i][1]-1]=1;
                }
                else if(queries[i][1]>0){
                    update(segTree,0,0,n-1,queries[i][1]-1,0);
                    peaks[queries[i][1]-1]=0;
                }
                if(queries[i][1]>0 && queries[i][1]<nums.size()-1 && nums[queries[i][1]]>nums[queries[i][1]-1] && nums[queries[i][1]]>nums[queries[i][1]+1]){
                    update(segTree,0,0,n-1,queries[i][1],1);
                    peaks[queries[i][1]]=1;
                }
                else if(queries[i][1]>=0){
                    update(segTree,0,0,n-1,queries[i][1],0);
                    peaks[queries[i][1]]=0;
                }
                if(queries[i][1]<nums.size()-2 && nums[queries[i][1]]<nums[queries[i][1]+1] && nums[queries[i][1]+2]<nums[queries[i][1]+1]){
                    update(segTree,0,0,n-1,queries[i][1]+1,1);
                    peaks[queries[i][1]+1]=1;
                }
                else if(queries[i][1]<nums.size()-1){
                    update(segTree,0,0,n-1,queries[i][1]+1,0);
                    peaks[queries[i][1]+1]=0;
                }
            }
        }
        return ans;
    }
};