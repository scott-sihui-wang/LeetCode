class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        bool visited[nums.size()];
        memset(visited,false,sizeof(visited));
        int inDegree[nums.size()];
        memset(inDegree,0,sizeof(inDegree));
        for(int i=0;i<nums.size();i++){
            inDegree[(i+nums[i]+nums.size())%nums.size()]++;
        }
        bool nonLoop=true;
        while(nonLoop){
            nonLoop=false;
            for(int i=0;i<nums.size();i++){
                if(visited[i]==false && inDegree[i]==0){
                    nonLoop=true;
                    visited[i]=true;
                    inDegree[(i+nums[i]+nums.size())%nums.size()]--;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                int j=i;
                int cnt=0;
                bool sameSign=true;
                while(visited[j]==false){
                    visited[j]=true;
                    cnt++;
                    int k=(j+nums[j]+nums.size())%nums.size();
                    if(nums[j]*nums[k]<0)sameSign=false;
                    j=k;
                }
                if(cnt>1 && sameSign==true)return true;
            }
        }
        return false;
    }
};