class Solution {
public:
    bool find(vector<int>& numbers, int begin, int end, int target, int& idx){
        while(begin<end){
            int mid=(begin+end)/2;
            if(numbers[mid]==target){
                idx=mid;
                return true;
            }
            else if(numbers[mid]<target){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        if(begin==end && numbers[begin]==target){
            idx=begin;
            return true;
        }
        return false;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin=0,end=numbers.size()-1;
        vector<int> ans;
        while(begin<end){
            int idx;
            bool res=find(numbers,begin+1,end,target-numbers[begin],idx);
            if(res){
                ans.push_back(begin+1);
                ans.push_back(idx+1);
                break;
            }
            else{
                begin=begin+1;
            }
        }
        return ans;
    }
};