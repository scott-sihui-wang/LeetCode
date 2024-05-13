class Solution {
public:
    struct disjointSet{
        int parent[26];
        disjointSet(){
            for(int i=0;i<26;i++){
                parent[i]=i;
            }
        }
        int find(int x){
            return parent[x]=(parent[x]==x?x:find(parent[x]));
        }
        void merge(int x,int y){
            int pa_x=find(x),pa_y=find(y);
            if(pa_x<pa_y){
                parent[pa_y]=pa_x;
            }
            else{
                parent[pa_x]=pa_y;
            }
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        disjointSet d;
        for(int i=0;i<s1.size();i++){
            d.merge(s1[i]-'a',s2[i]-'a');
        }
        string ans(baseStr.size(),' ');
        for(int i=0;i<baseStr.size();i++){
            ans[i]='a'+d.find(baseStr[i]-'a');
        }
        return ans;
    }
};