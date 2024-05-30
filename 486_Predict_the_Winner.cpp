class Solution {
public:
    bool solve(vector<int>& nums, int id1, int id2, int sumA, int sumB, bool isA){
        if(id2==id1+1){
            if(isA){
                return sumA+max(nums[id1],nums[id2])>=sumB+min(nums[id1],nums[id2]);
            }
            else{
                return sumA+max(nums[id1],nums[id2])>sumB+min(nums[id1],nums[id2]);
            }
        }
        if(solve(nums,id1+1,id2,sumB,sumA+nums[id1],!isA) && solve(nums,id1,id2-1,sumB,sumA+nums[id2],!isA)){
            return false;
        }
        else{
            return true;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()==1)return true;
        return solve(nums,0,nums.size()-1,0,0,true);
    }
};