class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n=skills.size();
        vector<pair<int,int>>s;
        for(int i=0;i<n;i++){
            s.push_back({skills[i],i});
        }
        sort(s.begin(),s.end());
        if(k>=n-1){
            return s[s.size()-1].second;
        }
        else{
            list<int>q;
            int win[n];
            memset(win,0,sizeof(win));
            for(int i=0;i<n;i++){
                q.push_back(i);
            }
            while(1){
                auto iter=q.begin();
                iter++;
                auto iter2=iter;
                iter--;
                int v1=*iter,v2=*iter2;
                if(skills[v1]>skills[v2]){
                    q.erase(iter2);
                    q.push_back(v2);
                    win[v1]++;
                    if(win[v1]==k){
                        return v1;
                    }
                    win[v2]=0;
                }
                else{
                    q.erase(iter);
                    q.push_back(v1);
                    win[v2]++;
                    if(win[v2]==k){
                        return v2;
                    }
                    win[v1]=0;
                }
            }
        }
        return -1;
    }
};