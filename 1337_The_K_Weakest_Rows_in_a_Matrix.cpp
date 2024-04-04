class Solution {
public:
    void sort(int cnt[],int idx[],int begin,int end){
        if(begin>=end)return;
        int i=begin;
        int j=end;
        int key1=cnt[begin];
        int key2=idx[begin];
        while(1){
            while(cnt[i]<key1 || (cnt[i]==key1 && idx[i]<=key2)){
                i++;
                if(i==end){
                    break;
                }
            }
            while(cnt[j]>key1 || (cnt[j]==key1 && idx[j]>=key2)){
                j--;
                if(j==begin){
                    break;
                }
            }
            if(i>=j)break;
            int tmp1=cnt[i];
            int tmp2=idx[i];
            cnt[i]=cnt[j];
            idx[i]=idx[j];
            cnt[j]=tmp1;
            idx[j]=tmp2;
        }
        cnt[begin]=cnt[j];
        idx[begin]=idx[j];
        cnt[j]=key1;
        idx[j]=key2;
        sort(cnt,idx,begin,j-1);
        sort(cnt,idx,j+1,end);
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        int cnt[m];
        int idx[m];
        for(int i=0;i<m;i++){
            cnt[i]=0;
            idx[i]=i;
            for(int j=0;j<n;j++){
                cnt[i]+=mat[i][j];
            }
        }
        sort(cnt,idx,0,m-1);
        vector<int>sol;
        for(int i=0;i<k;i++){
            sol.push_back(idx[i]);
        }
        return sol;
    }
};