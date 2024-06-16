class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            int j=0,k=0;
            while(j<s.size() && k<words[i].size()){
                char c=s[j];
                int cnt_s=0,cnt_w=0;
                while(s[j]==c){
                    cnt_s++;
                    j++;
                }
                while(words[i][k]==c){
                    cnt_w++;
                    k++;
                }
                if(cnt_w!=cnt_s && (cnt_s<3 || cnt_s<cnt_w || cnt_w==0)){
                    break;
                }
                if(j==s.size() && k==words[i].size()){
                    ans++;
                }
            }
        }
        return ans;
    }
};