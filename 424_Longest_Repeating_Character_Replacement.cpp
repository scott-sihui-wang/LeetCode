class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        set<char>dict;
        for(int i=0;i<s.size();i++){
            dict.insert(s[i]);
        }
        for(auto it=dict.begin();it!=dict.end();it++){
            char c=*it;
            int left=0,right=0,change=k;
            while(right<s.size()){
                while(right<s.size() && change>=0){
                    if(s[right]!=c){
                        change--;
                    }
                    right++;
                }
                if(change<0){
                    ans=max(ans,right-left-1);
                }
                else{
                    ans=max(ans,right-left);
                }
                while(left<right && change<0){
                    if(s[left]!=c){
                        change++;
                    }
                    left++;
                }
            }
        }
        return ans;
    }
};