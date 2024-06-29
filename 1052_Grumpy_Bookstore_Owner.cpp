class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0,diff=0,ans=INT_MIN;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                diff+=customers[i];
            }
        }
        ans=max(ans,diff);
        for(int i=1;i<=customers.size()-minutes;i++){
            if(grumpy[i-1]==1){
                diff-=customers[i-1];
            }
            if(grumpy[i+minutes-1]==1){
                diff+=customers[i+minutes-1];
            }
            ans=max(ans,diff);
        }
        return sum+ans;
    }
};