class Solution {
public:
    struct disjointSet{
        int size;
        int *rank,*parent;
        disjointSet(int n){
            size=n;
            rank=new int[n];
            parent=new int[n];
            for(int i=0;i<n;i++){
                rank[i]=0;
                parent[i]=i;
            }
        }
        ~disjointSet(){
            delete[] rank;
            delete[] parent;
        }
        int find(int x){
            return parent[x]=(parent[x]==x?x:find(parent[x]));
        }
        void merge(int x,int y){
            int x_pa=find(x),y_pa=find(y);
            if(rank[x]<rank[y]){
                parent[x_pa]=y_pa;
            }
            else{
                parent[y_pa]=x_pa;
                if(rank[x]==rank[y]){
                    rank[x]++;
                }
            }
        }
    };
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,int>sym;
        int id=0;
        for(int i=0;i<equations.size();i++){
            if(sym.find(equations[i][0])==sym.end()){
                sym[equations[i][0]]=id;
                id++;
            }
            if(sym.find(equations[i][3])==sym.end()){
                sym[equations[i][3]]=id;
                id++;
            }
        }
        disjointSet d(id);
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                d.merge(sym[equations[i][0]],sym[equations[i][3]]);
            }
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                if(d.find(sym[equations[i][0]])==d.find(sym[equations[i][3]]))return false;
            }
        }
        return true;
    }
};