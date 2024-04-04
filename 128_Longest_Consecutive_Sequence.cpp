class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        bool vis[len];
        memset(vis,0,sizeof(vis));
        unordered_map<int,int> dict;
        unordered_map<int,int>::iterator iter;
        for(int i=0;i<len;i++){
            dict[nums[i]]=i;
        }
        int max_len=0;
        for(int i=0;i<len;i++){
            if(vis[i]==false){
                int cnt=0;
                vis[i]=true;
                cnt++;
                int offset_h=1;
                iter=dict.find(nums[i]+offset_h);
                while(iter!=dict.end()){
                    vis[iter->second]=true;
                    offset_h++;
                    iter=dict.find(nums[i]+offset_h);
                }
                int offset_l=1;
                iter=dict.find(nums[i]-offset_l);
                while(iter!=dict.end()){
                    vis[iter->second]=true;
                    offset_l++;
                    iter=dict.find(nums[i]-offset_l);
                }
                cnt=offset_l+offset_h-1;
                max_len=max(max_len,cnt);
            }
        }
        return max_len;
    }
};