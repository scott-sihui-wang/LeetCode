class Solution {
public:
    void sort(vector<int>& arr,int begin,int end){
        if(begin>=end)return;
        int i=begin;
        int j=end;
        int key=arr[begin];
        while(1){
            while(arr[i]<=key){
                i++;
                if(i==end){
                    break;
                }
            }
            while(arr[j]>=key){
                j--;
                if(j==begin){
                    break;
                }
            }
            if(i>=j)break;
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
        arr[begin]=arr[j];
        arr[j]=key;
        sort(arr,begin,j-1);
        sort(arr,j+1,end);
    }
    void solve(int target,int item[],int cnt[],int len,int cur,int path[],vector<vector<int> >&sol){
        for(int i=0;i<=cnt[cur-1];i++){
            int residual=target-i*item[cur-1];
            if(residual>0){
                if(cur<len){
                    path[cur-1]=i;
                    solve(residual,item,cnt,len,cur+1,path,sol);
                }
            }
            else if(residual==0){
                path[cur-1]=i;
                vector<int> sub_sol;
                for(int j=0;j<cur;j++){
                    for(int k=0;k<path[j];k++){
                        sub_sol.push_back(item[j]);
                    }
                }
                sol.push_back(sub_sol);
                break;
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len=candidates.size();
        sort(candidates,0,len-1);
        int item[len];
        int cnt[len];
        int top=0;
        for(int i=0;i<len;i++){
            if(i==0){
                item[top]=candidates[i];
                cnt[top++]=1;
            }
            else{
                if(candidates[i]==candidates[i-1]){
                    cnt[top-1]++;
                }
                else{
                    item[top]=candidates[i];
                    cnt[top++]=1;
                }
            }
        }
        vector<vector<int> >sol;
        int path[top];
        solve(target,item,cnt,top,1,path,sol);
        return sol;
    }
};