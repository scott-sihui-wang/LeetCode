class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        set<int>p;
        for(int i=0;i<25;i++){
            p.insert(primes[i]);
        }
        int first=-1,last=-1;
        for(int i=0;i<nums.size();i++){
            if(p.find(nums[i])!=p.end()){
                if(first==-1){
                    first=i;
                    last=i;
                }
                else{
                    last=i;
                }
            }
        }
        return last-first;
    }
};