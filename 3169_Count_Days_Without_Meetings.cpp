class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int left_bound=meetings[0][0];
        int right_bound=meetings[0][1];
        int ans=days;
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]<=right_bound){
                right_bound=max(right_bound,meetings[i][1]);
            }
            else{
                ans-=right_bound-left_bound+1;
                left_bound=meetings[i][0];
                right_bound=meetings[i][1];
            }
        }
        ans-=right_bound-left_bound+1;
        return ans;
    }
};