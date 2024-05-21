class Solution {
public:
    void getPerm(vector<double>& cards,vector<bool>& visited, int idx,vector<double>& path,vector<vector<double>>& ans){
        if(idx==4){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<4;i++){
            if(visited[i]==false){
                path.push_back(cards[i]);
                visited[i]=true;
                getPerm(cards,visited,idx+1,path,ans);
                visited[i]=false;
                path.pop_back();
            }
        }
    }
    bool isValid4(double a,double b,double c,double d){
        return(isValid3(a+b,c,d) || isValid3(a-b,c,d) || isValid3(a*b,c,d) || isValid3(a/b,c,d) || isValid3(a,b+c,d) || isValid3(a,b-c,d) || isValid3(a,b*c,d) || isValid3(a,b/c,d) || isValid3(a,b,c+d) || isValid3(a,b,c-d) || isValid3(a,b,c*d) || isValid3(a,b,c/d));
    }
    bool isValid3(double a,double b,double c){
        return (isValid2(a+b,c) || isValid2(a-b,c) || isValid2(a*b,c) || isValid2(a/b,c) || isValid2(a,b+c) || isValid2(a,b-c) || isValid2(a,b*c) || isValid2(a,b/c));
    }
    bool isValid2(double a,double b){
        return abs(a+b-24)<0.01 || abs(a-b-24)<0.01 || abs(a*b-24)<0.01 || abs(a/b-24)<0.01;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> card_val;
        for(int i=0;i<4;i++){
            card_val.push_back((double)cards[i]);
        }
        vector<vector<double>> perms;
        vector<double> path;
        vector<bool> visited(4,false);
        getPerm(card_val,visited,0,path,perms);
        for(int i=0;i<perms.size();i++){
            if(isValid4(perms[i][0],perms[i][1],perms[i][2],perms[i][3]))return true;
        }
        return false;
    }
};