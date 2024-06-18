class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        map<int,int>::iterator iter=freq.begin();
        iter++;
        for(;iter!=freq.end();iter++){
            map<int,int>f=freq;
            int k=iter->first-freq.begin()->first;
            if(k%2!=0)continue;
            bool isValid=true;
            vector<int>ans;
            for(auto ptr=f.begin();ptr!=f.end();ptr++){
                if(ptr->second!=0){
                    if(f.find(ptr->first+k)==f.end()||f[ptr->first+k]<f[ptr->first]){
                        isValid=false;
                        break;
                    }
                    else{
                        for(int i=0;i<ptr->second;i++){
                            ans.push_back(ptr->first+k/2);
                        }
                        f[ptr->first+k]-=ptr->second;
                        ptr->second=0;
                    }
                }
            }
            if(isValid){
                return ans;
            }
        }
        return {};
    }
};