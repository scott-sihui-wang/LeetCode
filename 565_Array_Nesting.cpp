class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        bool visited[n];
        memset(visited,false,sizeof(visited));
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true)continue;
            int len=1,idx=i;
            visited[idx]=true;
            while(visited[nums[idx]]==false){
                idx=nums[idx];
                visited[idx]=true;
                len++;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};