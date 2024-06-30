class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=INT_MIN;
        set<int>s[k];
        for(int i=0;i<nums.size();i++){
            s[nums[i]%k].insert(i);
        }
        for(int i=0;i<k;i++){
            ans=max(ans,(int)s[i].size());
        }
        for(int i=0;i<k-1;i++){
            for(int j=i+1;j<k;j++){
                auto it1=s[i].begin();
                auto it2=s[j].begin();
                int cnt=0;
                while(it1!=s[i].end() && it2!=s[j].end()){
                    if(*it1<*it2){
                        while(it1!=s[i].end() && *it1<*it2){
                            it1++;
                        }
                    }
                    else{
                        while(it2!=s[j].end() && *it2<*it1){
                            it2++;
                        }
                    }
                    cnt++;
                }
                if(it1!=s[i].end()){
                    cnt++;
                }
                if(it2!=s[j].end()){
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};