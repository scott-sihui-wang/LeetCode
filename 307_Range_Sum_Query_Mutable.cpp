class NumArray {
public:
    int *segTree;
    int n;
    void buildTree(int *segTree,int idx,int left,int right,vector<int>& nums){
        if(left>right)return;
        if(left==right){
            segTree[idx]=nums[left];
            return;
        }
        int mid=(left+right)/2;
        buildTree(segTree, 2*idx+1,left,mid,nums);
        buildTree(segTree, 2*idx+2,mid+1,right,nums);
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
    }

    void update_traverse(int* segTree,int idx,int left,int right,int index,int val){
        if(left>right)return;
        if(left==right){
            segTree[idx]=val;
            return;
        }
        if(left<right){
            int mid=(left+right)/2;
            if(index<=mid){
                update_traverse(segTree,2*idx+1,left,mid,index,val);
            }
            else{
                update_traverse(segTree,2*idx+2,mid+1,right,index,val);
            }
            segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
        }
    }

    int sum_traverse(int *segTree,int idx,int left,int right,int s_left,int s_right){
        if(s_right<left || s_left>right)return 0;
        if(s_left<=left && s_right>=right){
            return segTree[idx];
        }
        else{
            int mid=(left+right)/2;
            return sum_traverse(segTree,2*idx+1,left,mid,s_left,s_right)+sum_traverse(segTree,2*idx+2,mid+1,right,s_left,s_right);
        }
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree=new int[4*n];
        buildTree(segTree,0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        update_traverse(segTree,0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sum_traverse(segTree,0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */