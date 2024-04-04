class Solution {
public:
    vector<string> printVertically(string s) {
        int len=s.length();
        char c[len][len];
        memset(c,0,sizeof(c));
        int i=0;
        int idx=0;
        int j;
        int max_j=0;
        while(i<len){
            j=0;
            while(i<len && s[i]!=' '){
                c[j++][idx]=s[i++];
            }
            max_j=max(max_j,j);
            idx++;
            i++;
        }
        for(int p=0;p<max_j;p++){
            int q=idx-1;
            while(q>=0 && c[p][q]==0){
                q--;
            }
            while(q>=0){
                if(c[p][q]==0){
                    c[p][q]=' ';
                }
                q--;
            }
        }
        vector<string>sol;
        for(int p=0;p<max_j;p++){
            sol.push_back(string(c[p]));
        }
        return sol;
    }
};