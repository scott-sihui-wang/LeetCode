class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>>tasks;
        for(int i=0;i<n;i++){
            tasks.push_back({difficulty[i],profit[i]});
        }
        sort(tasks.begin(),tasks.end());
        for(int i=1;i<n;i++){
            tasks[i].second=max(tasks[i-1].second,tasks[i].second);
        }
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int start=0,end=n-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(tasks[mid].first<=worker[i]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            if(end!=-1){
                ans+=tasks[end].second;
            }
        }
        return ans;
    }
};