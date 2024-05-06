class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int,int>buckets;
        for(int i=0;i<nums.size();i++){
            int bucket=nums[i]/(valueDiff+1);
            bucket=(nums[i]>=0?bucket:bucket-1);
            if(buckets.find(bucket)!=buckets.end())return true;
            buckets[bucket]=nums[i];
            if(buckets.find(bucket-1)!=buckets.end() && abs(buckets[bucket]-buckets[bucket-1])<=valueDiff)return true;
            if(buckets.find(bucket+1)!=buckets.end() && abs(buckets[bucket]-buckets[bucket+1])<=valueDiff)return true;
            if(i>=indexDiff){
                int rm=nums[i-indexDiff]/(valueDiff+1);
                rm=(nums[i-indexDiff]>=0?rm:rm-1);
                buckets.erase(rm);
            }
        }
        return false;
    }
};