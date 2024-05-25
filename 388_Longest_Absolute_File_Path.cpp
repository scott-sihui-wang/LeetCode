class Solution {
public:
    int lengthLongestPath(string input) {
        int ans=0;
        stack<pair<int,int>>s;
        int n=input.size();
        int i=0;
        int cnt_t=0;
        int prev=0;
        int len=0;
        bool isFile;
        while(i<n){
            isFile=false;
            cnt_t=0;
            while(i<n && input[i]=='\t'){
                i++;
                cnt_t++;
            }
            prev=i;
            while(i<n && input[i]!='\n'){
                if(input[i]=='.'){
                    isFile=true;
                }
                i++;
            }
            while(s.empty()==false && s.top().first>=cnt_t){
                len-=s.top().second;
                s.pop();
            }
            s.push({cnt_t,i-prev});
            len+=i-prev;
            if(isFile){
                ans=max(ans,len+cnt_t);
            }
            i++;
        }
        return ans;
    }
};