class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int begin=0, end=0;
        int len=words.size();
        while(begin<len){
            int sub_len=0;
            while(end<words.size() && sub_len+(sub_len==0?0:1)+words[end].size()<=maxWidth){
                sub_len+=words[end++].size()+(sub_len==0?0:1);
            }
            if(end-begin==1){
                ans.push_back(words[begin]+string(maxWidth-sub_len,' '));
            }
            else if(end<len){
                string s=words[begin];
                int n=(maxWidth-sub_len)/(end-begin-1);
                int m=(maxWidth-sub_len)%(end-begin-1);
                for(int i=1;i<end-begin;i++){
                    if(i<=m){
                        s+=string(n+2,' ');
                    }
                    else{
                        s+=string(n+1,' ');
                    }
                    s+=words[begin+i];
                }
                ans.push_back(s);
            }
            else{
                string s=words[begin];
                for(int i=1;i<end-begin;i++){
                    s+=string(1,' ');
                    s+=words[begin+i];
                }
                s+=string(maxWidth-sub_len,' ');
                ans.push_back(s);
            }
            begin=end;
        }
        return ans;
    }
};