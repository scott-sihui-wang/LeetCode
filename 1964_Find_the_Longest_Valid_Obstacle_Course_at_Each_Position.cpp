class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> ans(n);
        vector<int> seq;
        for(int i=0;i<n;i++){
            if(seq.empty() || seq[seq.size()-1]<=obstacles[i]){
                seq.push_back(obstacles[i]);
                ans[i]=seq.size();
            }
            else{
                int begin=0,end=seq.size()-1;
                while(begin<=end){
                    int mid=(begin+end)/2;
                    if(seq[mid]>obstacles[i]){
                        end=mid-1;
                    }
                    else{
                        begin=mid+1;
                    }
                }
                seq[begin]=obstacles[i];
                ans[i]=begin+1;
            }
        }
        return ans;
    }
};