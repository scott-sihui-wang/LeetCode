class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>unused;
        unordered_map<int,int>end_pos;
        for(int i=0;i<nums.size();i++){
            unused[nums[i]]++;
        }
        for(auto iter=unused.begin();iter!=unused.end();iter++){
            while(iter->second>0){
                if(end_pos[iter->first-1]>0){
                    unused[iter->first]--;
                    end_pos[iter->first-1]--;
                    end_pos[iter->first]++;
                }
                else if(unused[iter->first+1]>0 && unused[iter->first+2]>0){
                    unused[iter->first]--;
                    unused[iter->first+1]--;
                    unused[iter->first+2]--;
                    end_pos[iter->first+2]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};