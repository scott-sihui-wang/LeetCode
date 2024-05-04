class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int begin=0,end=people.size()-1;
        int ans=0;
        while(begin<=end){
            int sum=people[end--];
            if(sum+people[begin]<=limit){
                sum+=people[begin++];
            }
            ans++;
        }
        return ans;
    }
};