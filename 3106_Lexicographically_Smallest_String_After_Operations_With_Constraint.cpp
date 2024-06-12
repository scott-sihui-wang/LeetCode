class Solution {
public:
    int distance(char c){
        return min((c-'a'),('a'+26-c));
    }
    string getSmallestString(string s, int k) {
        string ans=s;
        int n=s.size();
        int i=0;
        while(i<n && k>0){
            int dist=distance(s[i]);
            if(dist<=k){
                ans[i]='a';
                k-=dist;
            }
            else{
                ans[i]=s[i]-k;
                k=0;
            }
            i++;
        }
        return ans;
    }
};