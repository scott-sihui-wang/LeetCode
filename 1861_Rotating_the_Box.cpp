class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=m-1;i>=0;i--){
            int idx=0;
            int cnt_stone=0,cnt_empty=0;
            while(idx<n){
                int start=idx;
                while(idx<n && box[i][idx]!='*'){
                    if(box[i][idx]=='#'){
                        cnt_stone++;
                    }
                    else if(box[i][idx]=='.'){
                        cnt_empty++;
                    }
                    idx++;
                }
                if(idx<n){
                    ans[idx][m-1-i]='*';
                    idx++;
                }
                while(cnt_empty>0){
                    ans[start][m-1-i]='.';
                    start++;
                    cnt_empty--;
                }
                while(cnt_stone>0){
                    ans[start][m-1-i]='#';
                    start++;
                    cnt_stone--;
                }
            }
        }
        return ans;
    }
};