class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2){
        return v1[0]<v2[0] || (v1[0]==v2[0] && v1[1]<v2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        bool visited[n];
        memset(visited,false,sizeof(visited));
        vector<vector<int>>ans(n,vector<int>(2));
        sort(people.begin(),people.end(),compare);
        for(int i=0;i<n;i++){
            int cnt=0;
            int j=0;
            for(;j<n;j++){
                if(cnt==people[i][1] && visited[j]==false){
                    break;
                }
                if(cnt<people[i][1] && (visited[j]==false || ans[j][0]>=people[i][0])){
                    cnt++;
                }
            }
            ans[j]={people[i][0],people[i][1]};
            visited[j]=true;
        }
        return ans;
    }
};