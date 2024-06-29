class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans=0;
        int n=reward1.size();
        priority_queue<int,vector<int>,less<int>>pq1,pq2;
        int cnt1=0,cnt2=0;
        for(int i=0;i<reward1.size();i++){
            if(reward1[i]>reward2[i]){
                ans+=reward1[i];
                cnt1++;
                pq2.push(reward2[i]-reward1[i]);
            }
            else if(reward1[i]==reward2[i]){
                ans+=reward1[i];
                cnt2++;
            }
            else{
                ans+=reward2[i];
                pq1.push(reward1[i]-reward2[i]);
            }
        }
        if(k<cnt1){
            while(k<cnt1){
                ans+=pq2.top();
                pq2.pop();
                k++;
            }
        }
        else if(k>cnt1+cnt2){
            while(k>cnt1+cnt2){
                ans+=pq1.top();
                pq1.pop();
                k--;
            }
        }
        return ans;
    }
};