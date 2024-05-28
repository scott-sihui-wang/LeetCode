class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int cost[n];
        for(int i=0;i<s.size();i++){
            cost[i]=abs(s[i]-t[i]);
        }
        int left=0,right=0,sum=0;
        int ans=0;
        while(right<n){
            while(right<n && sum<=maxCost){
                sum+=cost[right];
                right++;
            }
            if(sum>maxCost){
                ans=max(ans,right-left-1);
            }
            else{
                ans=max(ans,right-left);
            }
            while(left<right && sum>maxCost){
                sum-=cost[left];
                left++;
            }
        }
        return ans;
    }
};