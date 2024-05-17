class Solution {
public:
    struct disjointSet{
        int *parent;
        disjointSet(int n){
            parent=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        ~disjointSet(){
            delete[] parent;
        }
        int findParent(int x){
            return x==parent[x]?x:findParent(parent[x]);
        }
        void merge(int x,int y){
            int px=findParent(x),py=findParent(y);
            if(px<py){
                parent[py]=px;
            }
            else{
                parent[px]=py;
            }
        }
    };
    bool isSimilar(string s1, string s2){
        int diff=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                diff++;
            }
        }
        return (diff==2 || diff==0);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        disjointSet d(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    d.merge(i,j);
                }
            }
        }
        unordered_set<int> groups;
        int ans=0;
        for(int i=0;i<n;i++){
            int j=d.findParent(i);
            if(groups.find(j)==groups.end()){
                groups.insert(j);
                ans++;
            }
        }
        return ans;
    }
};